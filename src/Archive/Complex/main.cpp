#include <complex>
#include <iostream>
#include <vector>

using namespace std;

vector<complex<double>> nRoots(const int n) {
  double pi = 3.1415;

  vector<complex<double>> container;
  for (int i = 0; i < n; i++) {
    container.push_back(exp(complex<double>(0, 2*pi/n*i)));
  }
  return container;
}

int main() {
  vector<complex<double>> roots = nRoots(3);
  for (auto i : roots) {
    cout << i << endl;
  }
 }