#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double f(double x) {
    return 1/sqrt(x);//sin(100 * x) * std::exp(-x * x) * cos(2 * x);
}

int main() {
    double a = 1;
    double b = 9;
    vector<double> x;
    vector<int> N = {40, 80, 160, 320, 640, 1280, 2520, 5260, 10240, 20480, 40960, 120000};
    //number of roots//
    for (int j = 0; j < N.size(); j++) {
        x.resize(N[j]);
        x[0] = a;
        double h = (b - a) / N[j];
        double F38 = 0;
        double Fs = 0;
        for (int i = 1; i < N[j]; i++) {
            x[i] = a + i * h;
            // 3/8 method
            F38 += (f(x[i - 1]) + 3 * f((2 * x[i - 1] + x[i]) / 3) + 3 * f((x[i - 1] + 2 * x[i]) / 3) + f(x[i])) * h / 8;
            // Simpson's method
            Fs += (f(x[i - 1]) + 4 * f((x[i - 1] + x[i]) / 2) + f(x[i])) * h / 6;
        }
        cout << "Number of roots = " << N[j] << "; Rule 3/8 : I = " << F38 << " ; Simpson : I = " << Fs << endl;
    }
//Gauss method
    vector<vector<double>> A = {{-0.9324700, 0.1713245},
                                {-0.6612094, 0.3607616},
                                {-0.2386142, 0.4679140},
                                {0.2386142,  0.4679140},
                                {0.9324700,  0.1713245},
                                {0.6612094,  0.3607616}};
    double J = 0;
    for (int i = 0; i < 6; i++) {
        A[i][0] = (a + b) / 2 + (A[i][0]) * (b - a) / 2;
        J += (b - a) * A[i][1] * f(A[i][0]) / 2;
    }
    cout << "Gauss, 6 roots : I = " << J << endl;
    cout << "Gauss works herovo for this kind of functions."<< endl;
    cout << "3/8 and Simpson's methods works good at 1000> roots";
}
