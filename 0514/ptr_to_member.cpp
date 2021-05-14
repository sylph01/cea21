#include "../all.h"

struct C
{
  int x = 1;
  int y = 2;

  int f(int n) { return n; }
};

int main(){
  int C::* x_ptr = &C::x;
  int C::* y_ptr = &C::y;

  int (C::*f_ptr)(int) = &C::f;

  C object;

  std::cout << object.*x_ptr << std::endl;
  std::cout << object.*y_ptr << std::endl;

  std::cout << (object.*f_ptr)(0) << std::endl;
}
