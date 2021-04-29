#include "../all.h"

struct S {
  int n;

  S(int n) : n(n) {
    std::cout << "constructed: " << n << "\n";
  }
  ~S() {
    std::cout << "destructed: " << n << "\n";
  }
};

int main(){
  S a(1);
  { S b(2); }
  S c(3);
}
