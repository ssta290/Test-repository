#include <complex>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
  complex<double> z1 = exp(complex<double>(0, M_PI));

  cout << z1 << endl;

  complex<double> rotate = z1*exp(complex<double>(0, M_PI/2));

  cout << rotate << endl;

  complex<double> z3 = complex<double>(1, 2);

  cout << z3 << endl;
}