#include "../all.h"

template <typename T>
class own
{
private:
  T * ptr;
public:
  own(): ptr(new T){}
  ~own(){ delete ptr; }

  T* get() const { return ptr; }

  template <typename U>
  own(const own<U> &r): ptr(new T(*r.get())) {}

  own & operator=(const own &r){
    if(this != &r){
      *ptr = *r.get();
    }
    return this;
  }
};

int main(){
  own<int> a;
  own<double> b{a};

  // own<int> c = a;
  // this will result in double free!?
  // > free(): double free detected in tcache 2
  // > 中止 (コアダンプ)
}
