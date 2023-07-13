#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    int e = min(n+1, (int)pow(n, 1.0/3)+1);
    vector<int> cubes;
    for (int i = 1; i < e; i++) {
        cubes.push_back(pow(i, 3));
    }
    for (int i : cubes) {
        for (int j = i; j <= n; j++) {
            if (dp[j-i] != -1) {
                if (dp[j] == -1) dp[j] = dp[j-i]+1;
                else dp[j] = min(dp[j], dp[j-i]+1);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
