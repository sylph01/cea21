#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include "entry.h"
using namespace std;

void f(vector<Entry>& vec, list<Entry>& lst){
  sort(vec.begin(), vec.end());
  unique_copy(vec.begin(), vec.end(), lst.begin());
}

list<Entry> f2(vector<Entry>& vec){
  list<Entry> res;
  sort(vec.begin(), vec.end());
  unique_copy(vec.begin(), vec.end(), back_inserter(res)); // back_inserter is in <iterator>
  return res;
}

int main(){
  vector<Entry> phone_book = {
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Bertrand Arthur William Russell", 345678}
  };
  list<Entry> l(3); // need to allocate
  list<Entry> l2;

  // f(phone_book, l);
  l2 = f2(phone_book);

  for (const auto& x : l2)
    cout << x.name << " " << x.number << endl;
}
