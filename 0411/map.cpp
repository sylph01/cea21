#include <map>
#include <iostream>
using namespace std;

map<string, int> phone_book {
  {"David Hume", 123456},
  {"Karl Popper", 234567},
  {"Bertrand Arthur William Russell", 345678}
};

int get_number(const string& s){
  return phone_book[s];
}

int main(){
  cout << get_number("David Hume") << endl;
}
