#include "../all.h"

int main(){
  auto print = [](auto x){
    std::cout << x << "\n"s ;
    // this ""s operator is defined under std::literals::string_literals
    // https://en.cppreference.com/w/cpp/string/basic_string/operator%22%22s
    // so, to use without declaration, std::literals needs to be `using namespace`'d beforehand
  };

  print(123);
  print(3.14);
  print("hello");
}
