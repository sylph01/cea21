#include "../all.h"

template <typename T, std::size_t N>
struct array{
  T storage[N];
  T & operator[](std::size_t i){
    return storage[i];
  }
};

int main(){
  auto p = [](auto x){ std::cout << x << "\n"; };
  auto p_all = [=](auto x){
    for(auto iter = std::begin(x.storage); iter != std::end(x.storage); ++iter){
      p(*iter);
    }
  };

  array<int, 3> a3 = {1,2,3};
  array<double, 5> d5 = {0.1, 0.2, 0.3, 0.4, 0.5};

  p(a3[2]);
  p_all(d5);
}
