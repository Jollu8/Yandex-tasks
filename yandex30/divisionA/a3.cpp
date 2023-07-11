#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;
    vector<int> jollu(k);
    for (int i = 0; i < k; i++) {
        cin >> jollu[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (int x : jollu) {
        auto it = lower_bound(a.begin(), a.end(), x);
        cout << distance(a.begin(), it) << endl;
    }
    return 0;
}

