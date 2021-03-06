#include <iostream>
#include <vector>
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

void print_book(const vector<Entry>& book){
  for (int i = 0; i != book.size(); ++i)
    cout << book[i] << '\n';
}
void print_book2(const vector<Entry>& book){
  for (const auto& x : book)
    cout << x << endl;
}

int main(){
  vector<Entry> phone_book = {
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Bertrand Arthur William Russell", 345678}
  };

  print_book2(phone_book);
}
