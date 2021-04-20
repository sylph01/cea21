#include "../all.h"

int main(){
  std::vector<int> v = {1,2,3,4,5};

  for (auto i = std::begin(v); i != std::end(v); ++i){
    std::cout << *i << "\n";
  }
  // std::end(v) points to the "next of last entry" in v
}
