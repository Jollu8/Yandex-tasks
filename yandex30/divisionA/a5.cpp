#include <iostream>
#include <vector>
using namespace std;

int main() {
    int long n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int long ans = 0;
    for (int i = 1; i < n; i++) {
        ans += min(a[i], a[i-1]);
    }
    cout << ans << endl;
    return 0;
}
