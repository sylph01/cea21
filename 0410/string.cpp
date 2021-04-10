#include <iostream>
#include <string>
using namespace std;

string compose(const string& name, const string& domain){
  return name + '@' + domain;
}

string name = "Niels Stroustrup";

void m3(){
  string s = name.substr(6, 10);
  cout << name.replace(0, 5, "nicholas") << endl;
  name[0] = toupper(name[0]); // http://www.cplusplus.com/reference/cctype/toupper/ ; inside <cctype>
  cout << name << endl;
}

int main(){
  string s1 {"Four legs Good; two legs Baaad!"};
  string s2 = "hogehoge";

  auto addr = compose("sylph01", "s01.ninja");

  cout << s1 << endl;
  cout << s2 << endl;

  cout << addr << endl;

  m3();
  m3();
}
