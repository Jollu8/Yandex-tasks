#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    map<char, int> counter;
    int max_count = 0;
    string line;
    while (getline(cin, line)) {
        for (char c : line) {
            if (c != ' ') {
                counter[c]++;
                max_count = max(max_count, counter[c]);
            }
        }
    }

    for (int row_index = max_count; row_index > 0; row_index--) {
        for (auto const& [key, val] : counter) {
            cout << (row_index <= val ? '#' : ' ');
        }
        cout << endl;
    }

    for (auto const& [key, val] : counter) {
        cout << key;
    }
    cout << endl;

    return 0;
}
