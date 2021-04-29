#include "../all.h"

struct IntLike {
  int data;

  IntLike(int n = 0) : data(n) {};

  void print(){
    std::cout << data << "\n";
  }
};

// prefix operator
IntLike & operator++(IntLike & obj){
  ++obj.data;
  return obj;
}

IntLike & operator--(IntLike & obj){
  --obj.data;
  return obj;
}

// postfix operator
IntLike operator++(IntLike & obj, int){
  auto temp = obj;
  ++obj.data;
  return temp;
}

IntLike operator--(IntLike & obj, int){
  auto temp = obj;
  --obj.data;
  return temp;
}

int main(){
  IntLike il(0);
  il++;
  ++il;
  il.print();
}
