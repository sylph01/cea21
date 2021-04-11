#include <list>
#include <iostream>
#include "entry.h"
using namespace std;

list<Entry> phone_book = {
  {"David Hume", 123456},
  {"Karl Popper", 234567},
  {"Bertrand Arthur William Russell", 345678}
};

int get_number(const string& s){
  for (const auto& x : phone_book)
    if (x.name == s)
      return x.number;
  return 0;
}

int get_number_iter(const string& s){
  for (auto p = phone_book.begin(); p != phone_book.end(); ++p) // p is an iterator; *p is the actual value
    if (p->name == s) // if p points to a class with member m, then p->m is the equivalent of (*p).m
      return p->number;
  return 0;
}

void f(const Entry& ee, list<Entry>::iterator p, list<Entry>::iterator q){
  phone_book.insert(p, ee); // insert entry ee after p
  phone_book.erase(q);      // delete entry q
}

int main(){
  cout << get_number("Karl Popper") << endl;
  cout << get_number_iter("David Hume") << endl;
}
