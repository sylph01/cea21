#include "../all.h"

template <typename T>
std::remove_reference_t<T> && move(T && t) noexcept {
  // if an lvalue of type U is passed, template parameter T would be U &
  // then the && would be ignored, returning a type of U &, which does not match
  // so, the reference needs to be removed in order to apply && to U
  return static_cast<std::remove_reference_t<T> &&>(t);
}

int main(){
  int lvalue {};
  // passing lvalue
  int && r =  move(lvalue);
  // passing prvalue
  int && r2 = move(1 + 1);
}
