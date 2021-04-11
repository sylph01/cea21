using namespace std;

struct Entry {
  string name;
  int number;
};

bool operator<(const Entry& x, const Entry& y){
  return x.name < y.name;
}

bool operator==(const Entry& x, const Entry& y){
  return x.name == y.name && x.number == y.number;
}
