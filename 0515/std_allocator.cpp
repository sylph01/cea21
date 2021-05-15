#include "../all.h"

int main(){
  std::allocator<std::string> a;

  std::string *p = a.allocate(1);

  std::string * s = new(p) std::string("hello");

  std::cout << *s << std::endl;

  // s->~basic_string();
  std::destroy_at(s);

  a.deallocate(p, 1);
}
