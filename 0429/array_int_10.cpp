#include "../all.h"

struct array_int_10{
  int storage[10];

  int & operator[](std::size_t i){
    return storage[i];
  }
};

int main(){
  array_int_10 a = {0,1,2,3,4,5,6,7,8,9};
  auto b = a;

  std::cout << b[0] << b[1] << b[2] << "\n";
}
