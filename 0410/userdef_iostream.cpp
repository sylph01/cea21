#include <iostream>
using namespace std;

struct Entry {
  string name;
  int number;
};

ostream& operator<<(ostream& os, const Entry& e)
{
  return os << "{\"" << e.name << "\", " << e.number << "}";
}

istream& operator>>(istream& is, Entry& e){
  char c, c2;
  if (is >> c && c == '{' && is >> c2 && c2 == '"') {
    string name;
    while (is.get(c) && c != '"')
      name += c;

    if (is >> c && c == ',') {
      int number = 0;
      if (is >> number >> c && c == '}') {
        e = {name, number};
        return is;
      }
    }
  }
  is.setstate(ios_base::failbit);
  return is;
}

int main(){
  Entry e;
  e.name = "Hoge";
  e.number = 99;

  cout << e << endl;
  
  for (Entry ee; cin >> ee; )
    cout << ee << '\n';
}
