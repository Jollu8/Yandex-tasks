#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    dp[1][0] = 1;
    dp[0][1] = 1;
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] != -1) continue;
            if (i != 0 && j != 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1];
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[m - 1][n - 1];
    return 0;
}
