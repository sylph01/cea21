#include "../all.h"

template <typename Container>
struct back_inserter
{
  back_inserter(Container& c) : c(c) {}

  // --- boilerplate code ---
  // not used in output iterator
  using difference_type = void;
  using value_type = void;
  using reference = void;
  using pointer = void;
  // this is an output iterator
  using iterator_category = std::output_iterator_tag;
  // return self
  back_inserter & operator*() { return *this; }
  back_inserter & operator++() { return *this; }
  back_inserter & operator++(int) { return *this; }
  // end of boilerplate code

  back_inserter & operator =(const typename Container::value_type & value){
    c.push_back(value);
    return *this;
    /*
this line was specifically needed; without this the error would be:
back_inserter.cpp:24:3: warning: no return statement in function returning non-void [-Wreturn-type]
   23 |     c.push_back(value);
  +++ |+    return *this;
   24 |   }
      |   ^
    */
  }

  Container & c;
};

template <typename Container>
void f(Container const & c){
  std::vector<typename Container::value_type> temp;
  auto out = back_inserter(temp);
  std::copy(std::begin(c), std::end(c), out);
}

int main(){
  std::vector<int> v = {1,2,3,4,5};
  std::vector<int> temp = {1,2};
  auto out = back_inserter(temp);

  std::copy(std::begin(v), std::end(v), out);

  std::copy(std::begin(v), std::end(v), out);

  for(auto i = std::begin(temp); i != std::end(temp); ++i){
    std::cout << *i << std::endl;
  }
}
