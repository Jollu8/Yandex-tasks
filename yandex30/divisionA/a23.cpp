#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        int k = n / 2;
        cout << k * (k + 1) * (4 * k + 1) / 2 << endl;
    } else {
        int k = (n - 1) / 2;
        cout << (k + 1) * (4 * k * k + 7 * k + 2) / 2 << endl;
    }
    return 0;
}
