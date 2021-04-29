#include "../all.h"

int main(){
  auto print = [](auto s){ std::cout << s << "\n"; };
  int a[5];
  print(sizeof(a));
  print(sizeof(int) * 5);
  double b[5];
  print(sizeof(b));
  print(sizeof(double) * 5);
}
