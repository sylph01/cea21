#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
bool has_c(const string& s, char c){
  auto p = find(s.begin(), s.end(), c); // returns an iterator
  if (p != s.end())
    return true;
  else
    return false;
}
*/

bool has_c(const string& s, char c){
  return find(s.begin(), s.end(), c) != s.end();
}

void test_has_c(){
  string s = "hogehogefugafuga";
  string msg;

  if (has_c(s, 'p'))
    msg = s + " has p";
  else
    msg = s + " does not have p";

  cout << msg << endl;
}

vector<string::iterator> find_all(string& s, char c){
  vector<string::iterator> res;
  for (auto p = s.begin(); p != s.end(); ++p)
    if (*p == c)
      res.push_back(p);
  return res;
}

void test_find_all(){
  string m {"Mary had a little lamb"};
  auto ps = find_all(m, 'a');
  for (auto p : ps)
    if (*p != 'a')
      cerr << "a bug!\n";
}

int main(){
  // test_has_c();
  test_find_all();
}
