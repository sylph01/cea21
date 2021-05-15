#include "../all.h"

template<typename T, typename Allocator = std::allocator<T>>
class vector{
public:
  // nested types
  using value_type       = T;
  using pointer          = value_type *;
  using const_pointer    = const pointer;
  using reference        = value_type &;
  using const_reference  = const value_type &;
  using allocator_type   = Allocator;
  using size_type        = std::size_t;
  using difference_type  = std::ptrdiff_t;
  using iterator         = pointer;
  using const_iterator   = const_pointer;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  // Vector(std::size_t n = 0, Allocator a = Allocator());
  // default constructor
  vector() {}
  vector(const allocator_type & alloc) noexcept : alloc(alloc) {}
  vector(size_type size, const allocator_type & alloc = allocator_type()) : vector(alloc) {
    resize(size);
  }
  vector(size_type size, const_reference value, const allocator_type & alloc = allocator_type()) : vector(alloc) {
    resize(size, value);
  }

  /*
  template<typename InputIterator>
  vector(InputIterator first, InputIterator last, const Allocator & = Allocator()){
    reserve(std::distance(first, last));
    for(auto i = first; i != last; ++i){
      push_back(*i);
    }
  }

  vector(std::initializer_list<value_type> init, const Allocator & alloc = Allocator()) : vector(std::begin(init), std::end(init), alloc) {}
  */

  ~vector(){
    clear();
    deallocate();
  }

  void reserve(size_type sz){
    if (sz <= capacity())
      return;

    auto ptr = allocate(sz);
    auto old_first = first;
    auto old_last = last;
    auto old_capacity = capacity();

    first = ptr;
    last = first;
    reserved_last = first + sz;

    /*
    std::scope_exit e([&]{
      traits::deallocate(alloc, old_first, old_capacity);
    });
    */

    for(auto old_iter = old_first; old_iter != old_last; ++old_iter, ++last){
      construct(last, std::move(*old_iter));
      // this uses move semantics
    }
    for(auto riter = reverse_iterator(old_last), rend = reverse_iterator(old_first); riter != rend; ++riter){
      destroy(&*riter);
    }
    traits::deallocate(alloc, old_first, old_capacity);
    // storage SHOULD BE destroyed with scope_exit, but scope_exit does not compile :(
  }
  void resize(size_type sz){
    if (sz < size()){
      auto diff = size() - sz;
      destroy_until(rbegin() + diff);
      last = first + sz;
    } else if (sz > size()) {
      reserve(sz);
      for(; last != reserved_last; ++last){
        construct(last);
      }
    }
  }
  void resize(size_type sz, const_reference value){
    if (sz < size()){
      auto diff = size() - sz;
      destroy_until(rbegin() + diff);
      last = first + sz;
    } else if (sz > size()) {
      reserve(sz);
      for(; last != reserved_last; ++last){
        construct(last, value);
      }
    }
  }

  // copy
  vector(const vector &x);
  vector & operator =(const vector & x);

  void push_back(const_reference value){
    if (size() + 1 > capacity()){
      auto c = size();
      if (c == 0)
        c = 1;
      else
        c *= 2;

      reserve(c);
    }
    construct(last, value);
    ++last;
  }

  void shrink_to_fit(){
    if (size() == capacity())
      return;

    auto ptr = allocate(size());
    auto current_size = size();
    for(auto raw_ptr = ptr, iter = begin(), iter_end = end(); iter != iter_end; ++iter, ++raw_ptr){
      construct(raw_ptr, *iter);
    }
    clear();
    deallocate();
    first = ptr;
    last = ptr + current_size;
    reserved_last = last;
  }

  iterator begin() noexcept {
    return first;
  }
  iterator end() noexcept {
    return last;
  }
  iterator begin() const noexcept {
    return first;
  }
  iterator end() const noexcept {
    return last;
  }
  const_iterator cbegin() const noexcept {
    return first;
  }
  const_iterator cend() const noexcept {
    return last;
  }
  reverse_iterator rbegin() noexcept {
    return reverse_iterator{last};
  }
  reverse_iterator rend() noexcept {
    return reverse_iterator{first};
  }

  size_type size() const noexcept {
    return end() - begin();
  }
  bool empty() const noexcept {
    // return size() == 0;
    return begin() == end();
  }

  size_type capacity() const noexcept {
    return reserved_last - first;
  }

  reference operator[](size_type i) {
    return first[i];
  }
  const_reference operator[](size_type i) const {
    return first[i];
  }
  reference at(size_type i){
    if (i >= size())
      throw std::out_of_range("index is our of range.");
    return first[i];
  }
  const_reference at(size_type i) const {
    if (i >= size())
      throw std::out_of_range("index is our of range.");
    return first[i];
  }

  reference front() {
    return first;
  }
  const_reference front() const {
    return first;
  }
  reference back() {
    return last - 1;
  }
  const_reference back() const {
    return last - 1;
  }

  pointer data() noexcept {
    return first;
  }
  const_pointer data() const noexcept {
    return first;
  }
private:
  // data member
  /*
  pointer first = nullptr;
  size_type valid_size = nullptr;
  size_type allocated_size = nullptr;
  allocator_type alloc;
  */
  pointer first = nullptr;
  pointer last = nullptr;
  pointer reserved_last = nullptr;
  allocator_type alloc;
  // valid_size can be acquired by last - first
  // allocated_size can be acquired by reserved_last - first;
  using traits = std::allocator_traits<allocator_type>;

  pointer allocate(size_type n){
    return traits::allocate(alloc, n);
  }
  void deallocate(){
    traits::deallocate(alloc, first, capacity());
  }
  void construct(pointer ptr){
    traits::construct(alloc, ptr);
  }
  void construct(pointer ptr, const_reference value){
    traits::construct(alloc, ptr, value);
  }
  // move
  void construct(pointer ptr, value_type && value){
    traits::construct(alloc, ptr, std::move(value));
  }
  void destroy(pointer ptr){
    traits::destroy(alloc, ptr);
  }
  void destroy_until(reverse_iterator rend){
    for (auto riter = rbegin(); riter != rend; ++riter, --last){
      destroy(&*riter);
      // get `T &` by *riter, then apply & to get `T *`
    }
  }
  void clear() noexcept {
    destroy_until(rend());
  }
};

template <typename Vector>
void p_content(const Vector &v){
  for(auto i = v.begin(); i != v.end(); ++i){
    std::cout << *i << std::endl;
  }
  std::cout << "cap: " << v.capacity() << std::endl;
}
/*
  this would screw up if type signature was void p_content(Vector v)
  with following error:
  /usr/bin/ld: /tmp/cc9ymZmq.o: in function `main':
simple_vector.cpp:(.text+0xa5): undefined reference to `vector<int, std::allocator<int> >::vector(vector<int, std::allocator<int> > const&)'
collect2: error: ld returned 1 exit status
*/

int main(){
  vector<int> v(10, 1);
  v[2] = 99;
  v.resize(5);
  v.push_back(6);

  p_content(v);
  std::cout << std::endl;

  v.shrink_to_fit();
  p_content(v);
}
