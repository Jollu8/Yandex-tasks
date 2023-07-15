#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9 + 7;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int dp[n+1];
    fill(dp, dp+n+1, INF);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int k = 0; k <= i; k++) {
            dp[i] = min(dp[i], max(dp[i-k]+a, dp[k]+b));
        }
    }
    cout << dp[n] << endl;
    return 0;
}
