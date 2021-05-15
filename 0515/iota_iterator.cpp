#include "../all.h"

template <typename T>
struct iota_iterator
{
  // boilerplate code
  using difference_type = std::ptrdiff_t;
  using value_type = T;
  using reference = T &;
  using pointer = T *;
  using iterator_category = std::forward_iterator_tag;
  // end of boilerplate code

  T value;

  iota_iterator(T value = 0) : value(value) {}

  /*
  T & operator*() noexcept { return value; }
  const T & operator*() const noexcept { return value; }
  */
  reference operator*() noexcept { return value; }
  const reference operator*() const noexcept { return value; }

  iota_iterator & operator++() noexcept {
    ++value;
    return *this;
  }
  iota_iterator operator++(int) noexcept {
    auto temp = *this;
    ++*this;
    return temp;
  }

  bool operator==(iota_iterator const & i) const noexcept {
    return value == i.value;
  }
  bool operator!=(iota_iterator const & i) const noexcept {
    return !(*this == i);
  }
};

int main(){
  iota_iterator first(0), last(10);
  std::for_each(first, last, [](auto i){ std::cout << i << std::endl;});
}
