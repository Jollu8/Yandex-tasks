#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = (int)1e9 + 7;
const int N = 105;

int len, n;
int c[N];
int dp[N][N];

int solve(int l, int r) {
    if(r-l <= 1)
        return 0;
    if(dp[l][r] != MOD)
        return dp[l][r];
    for(int i = l+1; i < r; i++) {
        dp[l][i] = solve(l, i);
        dp[i][r] = solve(i, r);
        dp[l][r] = min(dp[l][r], dp[l][i]+dp[i][r]+c[r]-c[l]);
    }
    return dp[l][r];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> len >> n;
    c[0] = 0;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    c[n+1] = len;
    n = n+2;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = MOD;
    int ans = solve(0, n-1);
    cout << ans;
    return 0;
}
