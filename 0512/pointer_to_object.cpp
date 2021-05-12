#include "../all.h"

struct C
{
  int data_member;
  void member_function() {}
};

int main(){
  C object;
  C * pointer = &object;

  object.data_member = 1;
  object.member_function();

  pointer->data_member = 2;

  std::cout << (*pointer).data_member << std::endl;
  (*pointer).member_function();
}
