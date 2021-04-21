#include "../all.h"

auto swap = [](auto &a, auto &b){
  auto temp = a;
  a = b;
  b = temp;
};

int main(){
  int a = 1, b = 2;
  std::vector<int> v = {1,2,3,4,5};

  swap(a, b);
  swap(v.at(0), v.at(2));

  std::cout << a << " " << b << "\n";

  for(auto i : v){
    std::cout << i << "\n";
  }
}
