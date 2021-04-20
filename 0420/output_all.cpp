#include "../all.h"

auto output_all = [](auto first, auto last){
  for (auto iter = first; iter != last; ++iter){
    std::cout << *iter << "\n";
  }
};

auto output_to_iterator = [](auto first, auto last, auto output_iter){
  for (auto iter = first; iter != last; ++iter, ++output_iter){
    *output_iter = *iter;
  }
};

int main(){
  // std::vector<int> v = {1,2,3,4,5};
  // output_all(std::begin(v), std::end(v));

  std::istream_iterator<int> first(std::cin), last;
  // output_all(first, last);

  // std::filesystem::directory_iterator first("./"), last;
  // note that without a parameter, the constructor creates the end iterator by default
  // https://en.cppreference.com/w/cpp/filesystem/directory_iterator/directory_iterator

  // output_all(first, last);
  output_to_iterator(first, last, std::ostream_iterator<int>(std::cout));
}
