#include "../all.h"

int main(){
  int x = 0;
  int &ref = x;
  ++x;
  ++ref;

  std::cout << x << " " << ref << "\n";
}
