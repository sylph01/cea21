#include "../all.h"

int f(int x){
  std::cout << x << std::endl;
  return x;
}

int main(){
  using f_type = int(int);
  using f_pointer = f_type *;

  f_pointer ptr = &f;
  int (*ptr2)(int) = &f;

  (*ptr)(123);
  (*ptr2)(234);
}
