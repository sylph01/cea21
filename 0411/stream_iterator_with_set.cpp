#include <set>
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

int main(){
  string from, to;
  cin >> from >> to;

  ifstream is {from};
  ofstream os {to};

  set<string> b {istream_iterator<string> {is}, istream_iterator<string> {}};
  copy(b.begin(), b.end(), ostream_iterator<string>{os, "\n"});

  return !is.eof() || !os;
}
