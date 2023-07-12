
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k;
    cin >> k;
    vector<int> x, y;
    for (int i = 0; i < k; i++) {
        int xi, yi;
        cin >> xi >> yi;
        x.push_back(xi);
        y.push_back(yi);
    }
    cout << *min_element(x.begin(), x.end()) << " " << *min_element(y.begin(), y.end()) << " " << *max_element(x.begin(), x.end()) << " " << *max_element(y.begin(), y.end()) << endl;
}
