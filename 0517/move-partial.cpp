#include "../all.h"

/*
template <typename T>
T && move(T & t) noexcept {
  return static_cast<T &&>(t);
}
*/

template <typename T>
T && move(T && t) noexcept {
  return static_cast<T &&>(t);
}

int main(){
  int lvalue {};
  // passing lvalue
  // int && r =  move(lvalue);
  // passing rvalue
  int && r2 = move(1 + 1);
}
