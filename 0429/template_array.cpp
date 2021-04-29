#include "../all.h"

template <typename T, std::size_t N>
struct array{
  using value_type = T;
  using reference = T &;
  using const_reference = T const &;
  using size_type = std::size_t;

  size_type size() const {
    return N;
  }

  value_type storage[N];
  // this returns a modifiable reference
  reference operator[](size_type i){
    return storage[i];
  }
  // this returns a "const reference" T const &
  const_reference operator[](size_type i) const {
    return storage[i];
  }

  void fill(T const & u){
    for(std::size_t i = 0; i != N; ++i){
      storage[i] = u;
    }
  }
};

template <typename Array>
// as this takes a const reference...
void print(Array const & c){
  // c.size() calls the const member function
  for(std::size_t i = 0; i != c.size(); ++i){
    // this calls the const_reference const member function
    std::cout << c[i] << "\n";
  }
}

int main(){
  auto p = [](auto x){ std::cout << x << "\n"; };
  /*
  auto p_all = [=](auto x){
    for(auto iter = std::begin(x.storage); iter != std::end(x.storage); ++iter){
      p(*iter);
    }
  };
  */

  array<int, 3> i3 = {1,2,3};
  array<double, 5> d5 = {0.1, 0.2, 0.3, 0.4, 0.5};
  array<int, 9> i9;

  p(i3[2]);
  d5[2] = 1.3;
  print(d5);
  i9.fill(100);
  i9[0] = 1;
  print(i9);
}
