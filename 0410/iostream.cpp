#include <iostream>
using namespace std;

void f(){
  cout << 10;
}

void g(){
  int i {10};
  cout << i;
}

void h(int i){
  cout << "the value of i is ";
  cout << i;
  cout << '\n';
}

int main(){
  f();
  g();
  h(10);
}
