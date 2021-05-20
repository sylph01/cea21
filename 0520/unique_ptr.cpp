#include "../all.h"

template <typename T>
class unique_ptr
{
private:
  T * ptr = nullptr;
public:
  unique_ptr() {
    ptr = new T;
  }
  explicit unique_ptr(T * ptr) : ptr(ptr) {
    std::cout << "constructed ptr\n";
  }
  ~unique_ptr() {
    std::cout << "destructing ptr\n";
    delete ptr;
  }

  // copy is not allowed
  unique_ptr(const unique_ptr &) = delete;
  unique_ptr & operator=(const unique_ptr &) = delete;

  // move is allowed
  unique_ptr(unique_ptr && r) : ptr(r.ptr) { r.ptr = nullptr; }
  unique_ptr & operator=(unique_ptr && r) {
    delete ptr;
    ptr = r.ptr;
    r.ptr = nullptr;
  }

  T & operator*()  noexcept { return *ptr; }
  T * operator->() noexcept { return ptr; }
  T * get() noexcept { return ptr; }
};

int main(){
  {
    auto up = unique_ptr<int>();
    *up = 1;
    std::cout << *up << std::endl;
  }
  /*
  {
    int a {};
    int * p = &a;
    auto up2 = unique_ptr<int>(p);
    std::cout << *up2 << std::endl;
  }
  */
  // this results in an error
  // auto upc = up;
}
