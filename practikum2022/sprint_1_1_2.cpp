#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map <char,int> my_map;
    int k;
    cin >> k;
    int score = 0;
    string str;
    for (int i = 0; i < 4; ++i) {
        cin >> str;
        for (char j: str) {
            my_map[j]++;
        }
    }

    for (auto e: my_map) {
        if (e.first != 'c' && e.second <= k*2) {
            ++score;
        }
    }
    cout << "Result: " << score;
    return 0;
}
