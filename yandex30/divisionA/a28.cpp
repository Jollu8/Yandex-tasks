#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<char, int> m;
vector<string> v;
int d[6][101];

int main() {
    string s1="NSWEUD";
    for(int i=0; i<s1.size(); i++)
        m[s1[i]] = i;
    char c2[101];
    for(int i=0; i<6; i++) {
        cin.getline(c2, 101, '\n');
        string s2(c2);
        v.push_back(s2);
    }
    char c;
    int x;
    cin >> c >> x;

    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 101; j++)
            d[i][j] = 0;
    for(int i = 0; i < 6; i++)
        d[i][0] = 1;
    for(int i = 0; i < 6; i++)
        d[i][1] = 1+v[i].size();
    for(int j = 2; j < x; j++) {
        for(int i = 0; i < 6; i++) {
            d[i][j] += 1;
            for(auto u: v[i]) {
                d[i][j] += d[m[u]][j-1];
            }
        }
    }

    cout << d[m[c]][x-1];
    return 0;
}
