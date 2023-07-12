#include <iostream>
using namespace std;



int main() {

    int n, k, x, y;
    cin >> n >> k >> x >> y;
    int var = (x - 1) * 2 + y;
    int v1 = var - k;
    int v2 = var + k;
    if (v1 < 1 && v2 > n) {
        cout << -1 << endl;
    } else if (v1 >= 1 && v2 <= n) {
        int x1 = (v1 - 1) / 2 + 1;
        int x2 = (v2 - 1) / 2 + 1;
        int y1 = v1 % 2, y2 = v2 % 2;
        if (y1 == 0) y1 = 2;
        if (y2 == 0) y2 = 2;
        if (x - x1 < x2 - x) {
            cout << x1 << " " << y1 << endl;
        } else {
            cout << x2 << " " << y2 << endl;
        }
    } else if (v1 >= 1) {
        int jollu = v1 % 2;
        if (jollu == 0) jollu = 2;
        cout << (v1 - 1) / 2 + 1 << " " << jollu << endl;
    } else if (v2 <= n) {
        int y = v2 % 2;
        if (y == 0) y = 2;
        cout << (v2 - 1) / 2 + 1 << " " << y << endl;
    }
    return 0;
}
