#include <iostream>
using namespace std;

class complex {
  double re, im;
public:
  complex(double r, double i) : re{r}, im{i} {}
  complex(double r) : re{r}, im{0} {}
  complex() : re{0}, im{0} {}

  double real() const { return re; }
  void real(double d) { re = d; }
  double imag() const { return im; }
  void imag(double d) { im = d; }
  complex& operator+=(complex z) {
    re += z.re, im += z.im; return *this;
  }
  complex& operator-=(complex z) {
    re -= z.re, im -= z.im; return *this;
  }
  complex& operator*=(complex z) {
    double re_, im_;
    re_ = re;
    im_ = im;
    re = (re_ * z.re - im_ * z.im);
    im = (re_ * z.re + im_ * z.im);
    return *this;
  }
  complex& operator/=(complex z) {
    double re_, im_;
    re_ = re;
    im_ = im;
    re = (re_ * z.re + im_ * z.im) / (im_ * im_ + z.im * z.im);
    im = (im_ * z.re - re_ * z.im) / (im_ * im_ + z.im * z.im);
    return *this;
  }
};

complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a -= b; }
complex operator-(complex a) { return {-a.real(), -a.imag()}; }
complex operator*(complex a, complex b) { return a *= b; }
complex operator/(complex a, complex b) { return a /= b; }

bool operator==(complex a, complex b) {
  return a.real() == b.real() && a.imag() == b.imag();
}
bool operator!=(complex a, complex b) {
  return !(a==b);
}

complex sqrt(complex);

void f(complex z){
  complex a {2.3};
  complex b {1/a};
  complex c {a + z * complex(1, 2.3)};
  if (c != b)
    c = -(b/a)+2*b;
}

int main() {
  complex z{};
  f(z);
}
