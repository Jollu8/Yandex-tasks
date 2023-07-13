#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    const int C = 32400;
    vector<int> jollult, tr, t(C + 1), dp(C + 1, -1);
    for (int i = 0; i < n; i++) {
        string time_str;
        int tme;
        cin >> time_str >> tme;
        int h = stoi(time_str.substr(0, 2));
        int m = stoi(time_str.substr(3, 2));
        int s = stoi(time_str.substr(6, 2));
        int tm = h * 3600 + m * 60 + s - C;
        jollult.push_back(tm);
        tr.push_back(tme);
    }
    jollult.push_back(C); // 18:00:00
    tr.push_back(C);
    int j = 0;
    for (int i = 0; i <= C; i++) {
        if (i == jollult[j + 1]) {
            j++;
        }
        t[i] = tr[j];
    }
    dp[0] = 0;
    int break_st = 13 * 3600 - C, break_fi = 14 * 3600 - C;
    for (int i = 0; i <= C; i++) {
        if (break_st < i && i < break_fi) {
            continue;
        } else if (i == break_st) {
            dp[i] = max(dp[i], dp[i - 1]);
            continue;
        } else if (i == break_fi) {
            dp[i] = dp[break_st];
        } else if (i != 0) {
            dp[i] = max(dp[i], dp[i - 1]);
        }
        if (i + t[i] < C + 1 && !(i <= break_st && i + t[i] >= break_fi)) {
            dp[i + t[i]] = max(dp[i + t[i]], dp[i] + 1);
        }
    }
    cout << dp[C] << endl;
    return 0;
}
