#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push(x);
    }
    double ans = 0.0;
    while (a.size() > 1) {
        int x = a.top();
        a.pop();
        x += a.top();
        a.pop();
        ans += x * 0.05;
        a.push(x);
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
