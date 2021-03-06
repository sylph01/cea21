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

    std::cout << "----------\n";

    int int_min = std::numeric_limits<int>::min(); // in 8bit, 0b10000000
    int int_max = std::numeric_limits<int>::max(); // in 8bit, 0b01111111

    int int_min_minus_one = int_min - 1; // in 8bit, 0b01111111 = int_max
    int int_max_plus_one  = int_max + 1; // in 8bit, 0b10000000 = int_min

    std::cout << int_min << "\n" << int_max << "\n" << int_min_minus_one << "\n" << int_max_plus_one << "\n";

    std::cout << "----------\n";

    std::cout
      << "digits10"      << "\n"
      << "float: "       << std::numeric_limits<float>::digits10       << "\n"
      << "double: "      << std::numeric_limits<double>::digits10      << "\n"
      << "long double: " << std::numeric_limits<long double>::digits10 << "\n" ;

    std::cout << "----------\n";

    std::cout
      << "max_digits10"      << "\n"
      << "float: "           << std::numeric_limits<float>::max_digits10       << "\n"
      << "double: "          << std::numeric_limits<double>::max_digits10      << "\n"
      << "long double: "     << std::numeric_limits<long double>::max_digits10 << "\n" ;

    std::cout << "----------\n";

    std::cout
      << "epsilon"       << "\n"
      << "float: "       << std::numeric_limits<float>::epsilon()       << "\n"
      << "double: "      << std::numeric_limits<double>::epsilon()      << "\n"
      << "long double: " << std::numeric_limits<long double>::epsilon() << "\n" ;
}
