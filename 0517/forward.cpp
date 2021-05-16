#include "../all.h"

// note that this does not use forwarding remove_reference (T && t)
template<class T>
constexpr T && forward(std::remove_reference_t<T> & t) noexcept {
  return static_cast<T&&>(t);
}
template<class T>
constexpr T && forward(std::remove_reference_t<T> && t) noexcept {
  return static_cast<T&&>(t);
}

// using && on a template parameter allows function to take both an lvalue or an rvalue
template <typename T>
void g(T && t) { }

template <typename T>
void f(T && t) {
  // t of g(t) is an lvalue because it is bound to a name
  // if written like g(std::move(t)), everything passed to g will become an rvalue (=xvalue)
  // to pass an lvalue when t is an lvalue and an rvalue when t is an rvalue(xvalue):
  g(forward<T>(t));
}

int main(){
  int lvalue {};
  int && rvalue_ref = 0;
  int &  lvalue_ref = rvalue_ref;
  f(lvalue);
  f(0);
  f(rvalue_ref);
  f(lvalue_ref);
}
