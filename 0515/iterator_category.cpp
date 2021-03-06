#include "../all.h"

template<typename tag, typename Iterator>
constexpr bool is_category_of() {
  using iter_tag = typename std::iterator_traits<Iterator>::iterator_category;
  // with -std=c++17 this compiles; without -std=c++17, this should be changed to
  // return std::is_base_of<tag, iter_tag>();
  return std::is_base_of_v<tag, iter_tag>;
}

int main(){
  using iterator= std::vector<int>::iterator;
  bool b = is_category_of<std::forward_iterator_tag, iterator>();
  std::cout << b << std::endl;
}
