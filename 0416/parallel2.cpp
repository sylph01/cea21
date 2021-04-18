#include <iostream>
#include <thread>
#include <vector>
#include <functional>
using namespace std;

// note that without concrete implementations of f and F(), this will not compile(link)

void f(vector<double>& v);

struct F {
  vector<double>& v;
  F(vector<double>& vv) : v {vv} {}
  void operator()();
};

int main(){
  vector<double> some_vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<double> vec2 {10, 11, 12, 13, 14, 15};
 
  thread t1 {f, ref(some_vec)}; // ref() is in <functional>
  thread t2 {F{vec2}};

  t1.join();
  t2.join();
}
