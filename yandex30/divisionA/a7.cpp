#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int A[3], B[3], C[3];
    char ch;
    cin >> A[0] >> ch >> A[1] >> ch >> A[2];
    cin >> B[0] >> ch >> B[1] >> ch >> B[2];
    cin >> C[0] >> ch >> C[1] >> ch >> C[2];
    double t = ((C[0] - A[0] + (C[0] < A[0]) * 24) * 3600 + (C[1] - A[1]) * 60 + C[2] - A[2]) / 2.0;
    t = round(t);
    int T = B[0]*3600 + B[1]*60 + B[2] + t;
    int h = T / 3600 % 24, m = T / 60 % 60, s = T % 60;
    printf("%02d:%02d:%02d\n", h, m, s);
}
