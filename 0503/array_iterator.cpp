#include "../all.h"

// "class" to describe the iterator
template <typename Array>
struct array_iterator {
  Array &a;
  std::size_t i;
  array_iterator(Array &a, std::size_t i) : a(a), i(i) {}

  typename Array::reference operator *(){
    return a[i];
  }

  array_iterator & operator ++(){
    ++i;
    return *this;
  }
  array_iterator operator ++(int){
    array_iterator copy = *this;
    ++*this;
    return copy;
  }
  array_iterator & operator --(){
    --i;
    return *this;
  }
  array_iterator operator --(int){
    array_iterator copy = *this;
    --*this;
    return copy;
  }

  array_iterator &operator +=(std::size_t n){
    // this modifies the iterator directly
    i += n;
    return *this;
  }
  array_iterator operator +(std::size_t n) const {
    // this makes a copy, then calls the += operator that modifies the copied iterator
    auto copy = *this;
    copy += n;
    return copy;
  }

  array_iterator &operator -=(std::size_t n){
    // this modifies the iterator directly
    i -= n;
    return *this;
  }
  array_iterator operator -(std::size_t n) const {
    // this makes a copy, then calls the += operator that modifies the copied iterator
    auto copy = *this;
    copy -= n;
    return copy;
  }

  bool operator ==(array_iterator const & right){
    return i == right.i;
  }
  bool operator !=(array_iterator const & right){
    return i != right.i;
  }

  typename Array::reference operator[](std::size_t n) const {
    return *(*this + n);
  }

  bool operator < (array_iterator const & right) const {
    return i < right.i;
  }
  bool operator <= (array_iterator const & right) const {
    return i <= right.i;
  }
  bool operator > (array_iterator const & right) const {
    return i > right.i;
  }
  bool operator >= (array_iterator const & right) const {
    return i >= right.i;
  }
};

template <typename Array>
struct array_const_iterator
{
  Array const & a; // note that the array is const; const_iterator means that the iterator itself can be changed but the object cannot be changed
  std::size_t i;

  array_const_iterator(Array const & a, std::size_t i) : a(a), i(i) {}

  array_const_iterator(typename array_iterator<Array>::iterator const & iter) : a(iter.a), i(iter.i) {}

  array_const_iterator & operator++(){
    ++i;
    return *this;
  }
  array_const_iterator operator++(int){
    array_const_iterator copy = *this;
    ++*this;
    return copy;
  }
  array_const_iterator & operator --(){
    --i;
    return *this;
  }
  array_const_iterator operator --(int){
    array_const_iterator copy = *this;
    --*this;
    return copy;
  }

  typename Array::const_reference operator *(){
    return a[i];
  }
  typename Array::const_reference operator[](std::size_t n) const {
    return *(*this + n);
  }
};

template <typename T, std::size_t N>
struct array {
  T storage[N];

  using value_type = T;
  using reference = T &;
  using const_reference = T const &;
  using size_type = std::size_t;

  // same as array_iterator<array<T,N>>
  using iterator = array_iterator<array>;
  using const_iterator = array_const_iterator<array>;

  iterator begin(){
    return array_iterator(*this, 0);
  }
  // type of iterator
  // using iterator = array_iterator;

  // member function that returns an iterator
  iterator end(){
    return array_iterator(*this, N);
  }

  reference operator[](size_type i){
    return storage[i];
  }
};

template <typename T>
void p(T x){
  std::cout << x << std::endl;
}

int main(){
  array<int, 5> a = {1,2,3,4,5};
  auto iter = a.begin();
  p(*iter);
  ++iter;
  p(*iter);
  --iter;
  p(*iter);

  p(*(iter++));
  p(*iter);

  p("-----");

  for (auto iter2 = a.begin(); iter2 != a.end(); ++iter2){
    p(*iter2);
  }

  p("-----");

  auto iter3 = a.begin();
  p(*(iter3 + 1));
  p(*(iter3 + 2));
  p(*(iter3 + 3));

  p("-----");

  auto iter4 = a.end();
  p(*(iter4 - 1));
}
