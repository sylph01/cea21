#include "../all.h"

template <typename T>
std::remove_reference_t<T> && move(T && t) noexcept {
  return static_cast<std::remove_reference_t<T> &&>(t);
}

int main(){
  int lvalue {};
  // passing lvalue
  int && r =  move(lvalue);
  // passing rvalue
  int && r2 = move(1 + 1);
}
