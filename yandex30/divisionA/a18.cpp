#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    priority_queue<int, vector<int>, greater<int>> s;
    for (int i = 1; i <= k; i++) {
        s.push(i);
    }
    vector<int> ans(n);
    bool flag = true;
    vector<vector<int>> ti;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ti.push_back({a, -1, i});
        ti.push_back({b, 1, i});
    }
    sort(ti.begin(), ti.end());
    for (int i = 0; i < ti.size(); i++) {
        if (ti[i][1] == -1) {
            if (s.empty()) {
                cout << 0 << " " << ti[i][2] + 1 << endl;
                flag = false;
                break;
            }
            int mi = s.top();
            s.pop();
            ans[ti[i][2]] = mi;
        } else {
            s.push(ans[ti[i][2]]);
        }
    }
    if (flag) {
        for (int i: ans) {
            cout << i << endl;
        }
    }
}
