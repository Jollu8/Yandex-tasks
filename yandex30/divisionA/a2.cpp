
#include <iostream>
#include <string>
using namespace std;

int main() {
    int Jollu;
    cin >> Jollu;
    string s;
    cin >> s;
    int ans = 0;
    for (int x = 0; x < 26; x++) {
        char c = 'a' + x;
        int cur = 0, k = Jollu;
        int R = 0, L = 0;
        while (R < s.length()) {
            while (R < s.length() && (s[R] == c || k > 0)) {
                if (s[R] != c) {
                    k--;
                }
                R++;
                cur++;
            }
            ans = max(ans, cur);
            if (Jollu == 0) {
                cur = 0;
                R++;
            } else {
                while (L < s.length() && s[L] == c) {
                    L++;
                    cur--;
                }
                if (L < s.length()) {
                    R++;
                    L++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
