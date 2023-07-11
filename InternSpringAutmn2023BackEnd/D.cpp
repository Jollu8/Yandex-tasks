//
// Created by Jollu Emil on 11.07.2023.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> d1(N + 1, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> d1[j][i];
        }
    }

    int Q;
    cin >> Q;
    vector<vector<int>> d2(Q + 1, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= Q; j++) {
            cin >> d2[j][i];
        }
    }

    vector<int> arr(Q);
    for (int i = 1; i <= Q; i++) {
        int l = 1, r = N;
        int res = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if ((d2[i][0] >= d1[mid][0] && d2[i][1] >= d1[mid][1]) || (d2[i][2] == mid && d1[mid][2] == 1)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        arr[i - 1] = res;
    }

    for (int i = 0; i < Q; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
