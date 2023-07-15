#include <iostream>
#include <vector>
using namespace std;

int solve(long int i, long int j, vector<vector<long int>>& dp, vector<vector<long int>>& moves, long int n, long int m) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    long int ans = 0;
    for (auto move : moves) {
        long int x = i + move[0];
        long int y = j + move[1];
        if (0 <= x && x < n && 0 <= y && y < m) {
            ans += solve(x, y, dp, moves, n, m);
        }
    }
    dp[i][j] = ans;
    return ans;
}

int main() {
    long int n, m;
    cin >> n >> m;
    vector<vector<long int>> dp(n, vector<long int>(m, -1));
    dp[0][0] = 1;
    vector<vector<long int>> moves = {{-1, -2}, {-2, -1}, {-2, 1}, {1, -2}};
    cout << solve(n-1, m-1, dp, moves, n, m) << endl;
    return 0;
}