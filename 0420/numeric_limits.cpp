#include "../all.h"

int main(){
  std::cout
    << std::numeric_limits<int>::min() << "\n"
    << std::numeric_limits<int>::max() << "\n";

    std::cout
      << std::numeric_limits<unsigned int>::min() << "\n"
      << std::numeric_limits<unsigned int>::max() << "\n";

    std::cout
      << std::numeric_limits<long long>::min() << "\n"
      << std::numeric_limits<long long>::max() << "\n";
}
