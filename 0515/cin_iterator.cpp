#include "../all.h"

template<typename T>
struct cin_iterator
{
  // boilerplate code
  using difference_type = std::ptrdiff_t;
  using value_type = T;
  using reference = T &;
  using pointer = T *;
  using iterator_category = std::input_iterator_tag;
  // end of boilerplate code

  // constructor
  cin_iterator(bool fail = false) : fail(fail) { ++*this; }

  // return cached value
  // const value_type operator*() const {
  // const reference operator*() const { // this doesn't
  const T & operator*() const { // this works
    return value;
  }
/*
using `reference` here results in the following error:

cin_iterator.cpp: In instantiation of ‘T& cin_iterator<T>::operator*() const [with T = int; cin_iterator<T>::reference = int&]’:
/usr/include/c++/10/bits/stl_algobase.h:348:18:   required from ‘static _OI std::__copy_move<_IsMove, _IsSimple, _Category>::__copy_m(_II, _II, _OI) [with _II = cin_iterator<int>; _OI = std::back_insert_iterator<std::vector<int> >; bool _IsMove = false; bool _IsSimple = false; _Category = std::input_iterator_tag]’
/usr/include/c++/10/bits/stl_algobase.h:472:30:   required from ‘_OI std::__copy_move_a2(_II, _II, _OI) [with bool _IsMove = false; _II = cin_iterator<int>; _OI = std::back_insert_iterator<std::vector<int> >]’
/usr/include/c++/10/bits/stl_algobase.h:506:42:   required from ‘_OI std::__copy_move_a1(_II, _II, _OI) [with bool _IsMove = false; _II = cin_iterator<int>; _OI = std::back_insert_iterator<std::vector<int> >]’
/usr/include/c++/10/bits/stl_algobase.h:514:31:   required from ‘_OI std::__copy_move_a(_II, _II, _OI) [with bool _IsMove = false; _II = cin_iterator<int>; _OI = std::back_insert_iterator<std::vector<int> >]’
/usr/include/c++/10/bits/stl_algobase.h:569:7:   required from ‘_OI std::copy(_II, _II, _OI) [with _II = cin_iterator<int>; _OI = std::back_insert_iterator<std::vector<int> >]’
cin_iterator.cpp:55:52:   required from here
cin_iterator.cpp:20:12: error: binding reference of type ‘cin_iterator<int>::reference’ {aka ‘int&’} to ‘const value_type’ {aka ‘const int’} discards qualifiers
   20 |     return value;
      |            ^~~~~
*/
  cin_iterator & operator++() {
    if (!fail){
      std::cin >> value;
      fail = std::cin.fail();
    }
    return *this;
  }

  cin_iterator operator ++(int) {
    auto old = *this;
    ++*this;
    return old;
  }

  bool fail;
  value_type value;
};

template <typename T>
bool operator==(cin_iterator<T> const & l, cin_iterator<T> const &r) {
  return l.fail == r.fail;
}

template <typename T>
bool operator!=(cin_iterator<T> const & l, cin_iterator<T> const &r) {
  return !(l == r);
}

int main(){
  cin_iterator<int> input, fail(true);
  std::vector<int> buffer;

  std::copy(input, fail, std::back_inserter(buffer));

  for(auto i = std::begin(buffer); i != std::end(buffer); ++i){
    std::cout << *i << std::endl;
  }
}
