#include <iostream>
using namespace std;

void f(){
  int i;
  cin >> i;

  double d;
  cin >> d;

  cout << i << endl;
  cout << d << endl;
}

void g(){
  cout << "Please enter your name" << endl;
  string str;
  getline(cin, str);
  cout << "Hello, " << str << "!\n";
}

int main(){
  // f();
  g();
}
