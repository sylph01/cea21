#include "../all.h"

// note that this needs to be compiled with -std=c++17,
// because std::byte is introduced in c++17

template <typename To, typename From>
To bit_cast(From const & from) {
  To to;
  memcpy(&to, &from, sizeof(To));
  return to;
}

void * memcpy(void * dest, void const * src, std::size_t n) {
  auto d = static_cast<std::byte *>(dest);
  auto s = static_cast<std::byte const *>(src);

  auto last = s + n;

  while (s != last){
    *d = *s;
    ++d;
    ++s;
  }

  return dest;
}

int main(){
  std::byte data[4];
  std::cout << bit_cast<std::uintptr_t>(&data[0]) << std::endl;
}
