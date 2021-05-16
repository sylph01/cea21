#include "../all.h"

void f(const int &){
  std::cout << "lvalue\n";
}
void f(const int &&){
  std::cout << "rvalue\n";
}

int main(){
  // constexpr int object {};
  int object {};

  f(object); // lvalue
  f(object + object); // prvalue
  // f([]{return object;}())
  f([](auto x){ return x; }(object)); // prvalue
  f(std::move(object)); // xvalue

  f(1); // prvalue
  f(1 + 1); // prvalue
  f(std::move(1)); // xvalue
}
