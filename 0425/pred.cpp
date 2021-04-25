#include "../all.h"

auto all_of = [](auto first, auto last, auto pred){
  for(auto iter = first; iter != last; ++iter){
    if(pred(*iter) == false){
      return false;
    }
  }
  return true;
};

auto any_of = [](auto first, auto last, auto pred){
  for(auto iter = first; iter != last; ++iter){
    if(pred(*iter) == true){
      return true;
    }
  }
  return false;
};

auto none_of = [](auto first, auto last, auto pred){
  for(auto iter = first; iter != last; ++iter){
    if(pred(*iter) == false){
      return true;
    }
  }
  return false;
};

int main(){
  std::vector<int> v = {1,2,3,4,5};

  std::cout << std::boolalpha;
  std::cout << all_of(std::begin(v), std::end(v), [](auto x){ return x <= 5; }) << "\n";
  std::cout << none_of(std::begin(v), std::end(v), [](auto x){ return x <= 5; }) << "\n";
  std::cout << any_of(std::begin(v), std::end(v), [](auto x){ return x == 3; }) << "\n";
  std::cout << std::noboolalpha;
}
