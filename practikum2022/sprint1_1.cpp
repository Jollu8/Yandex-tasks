#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> street;
    for (int i = 0; i < n; ++i) {
        int number;
        cin >>number;
        street.push_back(number);
    }
    if (n > 0) {
        vector <int> result(n);

        int l = 0;
        int r = 0;
        bool find = false;

        while (r < n) {
            if (street[r]==0) {
                if (find) {
                    while (l <= r) {
                        int temp = r - l;
                        result[l] = temp < result[l] ? temp : result[l];
                        ++l;
                    }
                    ++r;
                } else {
                    while (l <= r) {
                        result[l] = r - l;
                        ++l;
                    }
                    ++r;
                    find = true;
                }

            } else {
                result[r] = r - l+1;
                ++r;
            }
        }
        for (auto i: result) {
            cout << i << " ";
        }
    }

    return 0;
}