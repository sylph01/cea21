#include <iostream>
using namespace std;

void print() {
  int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (auto x : v)
    cout << x << '\n';

  for (auto x : {11, 12, 13, 14, 15})
    cout << x << '\n';
}

void increment() {
  int v[] = {0, 1, 2, 3, 4, 5, 6};

  // postfix & = "reference to"
  for (auto& x : v)
    ++x;

  for (auto x : v)
    cout << x << '\n';
}

int count_x(char* p, char x) {
  if (p == nullptr) return 0;
  int count = 0;
  for (; *p != 0; ++p)
    if (*p == x)
      ++count;
  return count;
}

void puts(string x){
  cout << x << '\n';
}

int main() {
  puts("print");
  print();

  puts("increment");
  increment();
  
  puts("count_x");
  char chs[] = {'a', 'a', 'b', 'c', 'c', 'c'};
  cout << count_x(chs, 'b') << '\n';
}
