#include "../all.h"

struct fractional {
  int num;
  int denom;

  fractional(int num, int denom = 1) : num(num), denom(denom) {};

  void print(){
    std::cout << num << "/" << denom << "\n";
  }

  fractional operator+(fractional const & r){
    if (denom == r.denom)
      return fractional{num + r.num, denom};
    else
      return fractional{num * r.denom + r.num * denom, denom * r.denom};
  }

  fractional operator-(fractional const & r){
    if (denom == r.denom)
      return fractional{num - r.num, denom};
    else
      return fractional{num * r.denom - r.num * denom, denom * r.denom};
  }

  fractional operator*(fractional const & r){
    return fractional{num * r.num, denom * r.denom};
  }

  fractional operator/(fractional const & r){
    return fractional{num * r.denom, denom * r.num};
  }
};

/*
fractional operator+(fractional & l, fractional & r){
  if (l.denom == r.denom)
    return fractional{l.num + r.num, l.denom};
  else
    return fractional{l.num * r.denom + r.num * l.denom, l.denom * r.denom};
}
*/

int main(){
  fractional a(1);
  fractional b(2);
  (a + b).print();
  (a - b).print();
  (a * b).print();
  (a / b).print();
}
