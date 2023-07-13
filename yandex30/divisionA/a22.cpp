#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if (a[j] > a[i])
                dp[j] = max(dp[j], dp[i] + 1);
        }
    }

    int mx=1, mix=0;
    for(int i = 0; i < n; i++){
        if(dp[i] > mx) {
            mx = dp[i];
            mix = i;
        }
    }
    vector<int> ans;
    ans.push_back(a[mix]);
    int i = mix;
    while(dp[i] != 1) {
        int j;
        for(j = i; j >= 0; --j) {
            if (dp[j]+1 == dp[i] && a[j] < a[i])
                break;
        }
        ans.push_back(a[j]);
        i = j;
    }

    reverse(ans.begin(), ans.end());
    for (auto u: ans)
        cout << u << ' ';

    return 0;
}
