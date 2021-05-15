#include "../all.h"

int main(){
  std::allocator<std::string> a;
  // using traits = std::allocator_traits<std::allocator<int>>;
  using traits = std::allocator_traits<decltype(a)>;
  std::string * p = traits::allocate(a, 1);
  // std::string * s = traits::construct(a, p, "hello");
  traits::construct(a, p, "hello");

  std::cout << *p << std::endl;

  //traits::destroy(a, s);
  traits::destroy(a, p);

  traits::deallocate(a, p, 1);
}
