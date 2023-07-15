#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size() + 1, m = b.size() + 1;
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j && i == 0) dp[i][j] = 0;
            else if (j == 0 && i > 0) dp[i][j] = i;
            else if (i == 0 && j > 0) dp[i][j] = j;
            else dp[i][j] = min(dp[i][j-1]+1, min(dp[i-1][j]+1, dp[i-1][j-1]+int(a[i-1]!=b[j-1])));
        }
    }
    cout << dp[n-1][m-1] << endl;
    return 0;
}
