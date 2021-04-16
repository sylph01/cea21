#include <iostream>
#include <thread> // compile me with `-pthread` option
using namespace std;

void f(){ cout << "Hello "; }

struct F {
  void operator()() { cout << "Parallel World!\n"; }
};

int main(){
  thread t1 {f};
  thread t2 {F()};

  t1.join();
  t2.join();
}
