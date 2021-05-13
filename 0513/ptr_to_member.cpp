#include "../all.h"

struct Object
{
  int data_member;
  void member_function(){
    std::cout << data_member << std::endl;
  }
};

int main(){
  int Object::* int_ptr = &Object::data_member;
  void (Object::* func_ptr)() = &Object::member_function;

  Object object;

  object.*int_ptr = 123;
  (object.*func_ptr)();

  Object another_object;
  another_object.data_member = 456;

  (another_object.*func_ptr)();
}
