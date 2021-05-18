#include "../all.h"

template <typename T>
class dynamic_array
{
private:
  T* first;
  T* last;
public:
  dynamic_array(std::size_t size = 0): first(new T[size]), last(first + size) {}
  ~dynamic_array() { delete [] first; }

  T & operator [] (std::size_t i) const noexcept {
    return first[i];
  }
  std::size_t size() const noexcept {
    return last - first;
  }
  T * begin() const noexcept {
    return first;
  }
  T * end() const noexcept {
    return last;
  }

  dynamic_array(const dynamic_array & r) : first(new T[r.size()]), last(first + r.size()) {
    std::copy(r.begin(), r.end(), begin());
  }
  dynamic_array & operator=(const dynamic_array & r){
    if (this != &r && size() != r.size()){
      delete first;
      first = new T[r.size()];
      last = first + r.size();

      std::copy(r.begin(), r.end(), begin());
    } else if (this != &r) {
      // without this clause, copy would not happen
      std::copy(r.begin(), r.end(), begin());
    }
    return *this;
  }

  // move constructor
  dynamic_array(dynamic_array && r) : first(r.first), last(r.last){
    r.first = nullptr;
    r.last  = nullptr;
  }
  dynamic_array & operator=(dynamic_array && r){
    // release storage of destination object
    delete first;
    // move ownership to destination object
    first = r.first;
    last  = r.last;
    // release ownership from source object
    r.first = nullptr;
    r.last  = nullptr;

    return *this;
  }
  // note that move constructors take a *non-const* rvalue reference;
  // to do a move, you have to release ownership from source object
};

template <typename T>
void print_all(const T & a){
  std::for_each(a.begin(), a.end(), [](auto i){ std::cout << i << std::endl;});
}

int main(){
  dynamic_array<int> a(5);
  dynamic_array<int> b(5);
  a[0] = 1;
  a[1] = 2;
  b = a; // this should invoke copy assignment

  dynamic_array<int> dest = std::move(a); // then a is moved into dest

  print_all(b);
  print_all(dest);
}
