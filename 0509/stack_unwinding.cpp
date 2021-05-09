#include "../all.h"

struct Object
{
  std::string name;

  Object(std::string const & name) : name(name) {
    std::cout << name << " is constructed.\n";
  }
  ~Object(){
    std::cout << name << " is destructed.\n";
  }
};

void f(){
  Object obj("f");
  throw 0;
}

void g(){
  Object obj("g");
  f();
}

int main(){
  Object obj("main");

  try {
    g();
  } catch (int e) {
    std::cout << e << " is caught.\n";
  }
}
