#include "../all.h"

// to avoid copy, use lvalue reference
// also to avoid overwriting the value use const
void f(std::vector<int> const & v){
  std::cout << v.at(100);
}

int main(){
  std::vector<int> v(10000, 1);

  f(v);
}
