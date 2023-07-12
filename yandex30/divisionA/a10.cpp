#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int main() {
    string s;
    cin >> s;
    map<char, int> a;
    int n = s.length();
    for (char c : s) {
        a[c] = 0;
    }
    vector<int> d(n);
    d[0] = n;
    a[s[0]] += d[0];
    for (int i = 1; i < n; i++) {
        char c = s[i];
        d[i] = d[i-1] - i + n - i;
        a[c] += d[i];
    }
    for (auto const& [k, v] : a) {
        cout << k << ": " << v << endl;
    }
    return 0;
}
