#ifndef NAIVE_FT_CPP
#define NAIVE_FT_CPP

#include <complex>
#include <vector>
#include <cmath>

using namespace std;
 
vector<complex<double>> discreteFourierTransform(const vector<double> &input) {
    size_t N = size(input);
    vector<complex<double>> X(N);
    double c = 1.0/N;

    for (int k = 0; k < N; k++) {
        // Compute X_k for given k
        X[k] = 0;
        for (int n = 0; n < N; n++) {
            X[k] += input[n]*exp(complex<double>(0, 2*M_PI*n/N*k));
        }
        X[k] *= c;
    }

    return X;
}

#endif  // NAIVE_FT_CPP
