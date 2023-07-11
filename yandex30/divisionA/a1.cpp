//
// Created by Jollu Emil on 11.07.2023.
//
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ifstream input("input.txt");
    string a, line;
    while (getline(input, line)) {
        a += line + '\n';
    }
    input.close();
    map<char, int> m;
    for (char i : a) {
        if (i == ' ' || i == '\n') continue;
        if (m.find(i) == m.end()) m[i] = 1;
        else m[i]++;
    }
    ofstream output("output.txt", ios::app);
    string ans;
    int mx = max_element(m.begin(), m.end(), [](const pair<char, int>& p1, const pair<char, int>& p2) {return p1.second < p2.second;})->second;
    while (mx > 0) {
        for (auto k : m) {
            if (k.second >= mx) ans += '#';
            else ans += ' ';
        }
        output << ans << endl;
        ans = "";
        mx--;
    }
    for (auto k : m) ans += k.first;
    output << ans << endl;
    output.close();
}
