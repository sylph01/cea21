#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename T>
using Iterator = typename T::iterator;

template<typename C, typename V>
vector<Iterator<C>> find_all(C& c, V v){
  vector<Iterator<C>> res;
  for (auto p = c.begin(); p != c.end(); ++p)
    if (*p == v)
      res.push_back(p);
  return res;
}

void test(){
  string m {"Mary had a little lamb"};
  auto psm = find_all(m, 'a');
  cout << psm.size() << endl;

  list<double> ld {1.1, 1.2, 1.3, 2.2, 2.3, 1.1};
  auto psld = find_all(ld, 1.1);
  cout << psld.size() << endl;

  vector<string> vs {"red", "blue", "green", "green", "orange", "green"};
  auto psvs = find_all (vs, "green");
  cout << psvs.size() << endl;
}

int main(){
  test();
}
