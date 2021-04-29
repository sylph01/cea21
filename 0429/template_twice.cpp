#include "../all.h"

template <typename T>
T twice(T n){
  return n * 2;
}

int main(){
  auto p = [](auto x){ std::cout << x << "\n"; };

  p(twice(2));
  p(twice(3.14));
}
