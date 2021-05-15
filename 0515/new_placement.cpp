#include "../all.h"

struct Logger
{
  std::string name;
  Logger(std::string name) : name(name) { std::cout << name << " is constructed.\n"; }
  ~Logger() { std::cout << name << " is destructed.\n"; }
};

int main(){
  void * ptr = ::operator new (sizeof(Logger));
  Logger * logger_ptr = new (ptr) Logger{"Alice"};
  std::cout << logger_ptr->name << std::endl;
  logger_ptr->~Logger();
  ::operator delete(ptr);

  {
    Logger * logger_ptr2 = new Logger("Hoge");
    delete(logger_ptr2);
  }

  int * int_array_ptr = new int[5]{1,2,3,4,5};

  delete [] int_array_ptr;
}
