#include <iostream>

int main(){
  auto print = [](auto x){
    std::cout << x << "\n" ;
  };

  print(123);
  print(3.14);
  print("hello");
}
