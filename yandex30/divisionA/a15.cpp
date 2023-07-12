#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    vector<char> alpha = {'<', '>', '/'};
    for (int i = 0; i < 26; i++) {
        alpha.push_back('a' + i);
    }
    for (char ch : alpha) {
        bool flag = false;
        for (int k = 0; k < s.length(); k++) {
            if (k > 0 && k < s.length() - 1) {
                if (ch == '<' && (s[k - 1] != '>' || s[k + 1] == '>' || s[k + 1] == '<')) {
                    continue;
                } else if (ch == '>' && (s[k + 1] != '<' || s[k - 1] == '>' || s[k - 1] == '<')) {
                    continue;
                } else if (ch == '/' && (s[k - 1] != '<' || s[k + 1] == '>' || s[k + 1] == '<')) {
                    continue;
                }
            }
            string a = s.substr(0, k) + ch + s.substr(k + 1);
            vector<string> d;
            int l = 0;
            bool flag2 = true;
            while (l < a.length() && flag2) {
                int r = l;
                string st(1, a[r]);
                if (st != "<") {
                    flag2 = false;
                    continue;
                }
                r++;
                bool ex = false;
                while (r < a.length() && a[r] != '>' && a[r] != '<') {
                    if (a[r] == '/' && !ex && r - l == 1) {
                        ex = true;
                        r++;
                        continue;
                    } else if (a[r] == '/' && (ex || r - l != 1)) {
                        flag2 = false;
                        break;
                    }
                    st += a[r];
                    r++;
                }
                if (r < a.length()) st += a[r];
                if (st[0] == '<' && st[st.length() - 1] == '>') {
                    if (!d.empty() && ex && flag2 && d.back().length() == st.length() && d.back() == st) {
                        d.pop_back();
                    } else if (!ex && flag2) {
                        d.push_back(st);
                    } else {
                        flag2 = false;
                        continue;
                    }
                } else {
                    flag2 = false;
                    continue;
                }
                l = r + 1;
            }
            if (d.empty() && flag2) {
                cout << a << endl;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    return 0;
}
