#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        double z = 0;
        cin >> n;
        n++;
        vector<double> a(n);
        for (int j = 1; j < n; j++) {
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        vector<double> stack;
        for (int j = 1; j < n; j++) {
            if (stack.size() > 0 && a[j] <= stack.back()) {
                stack.push_back(a[j]);
            } else {
                while (stack.size() > 0 && a[j] > stack.back() && abs(stack.back()-a[z]) <= 1e-7) {
                    stack.pop_back();
                    z++;
                }
                stack.push_back(a[j]);
            }
        }
        while (stack.size() > 0 && abs(stack.back()-a[z]) <= 1e-7) {
            stack.pop_back();
            z++;
        }
        if (stack.size() == 0 && z == a.size()) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}