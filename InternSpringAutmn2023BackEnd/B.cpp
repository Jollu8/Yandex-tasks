//
// Created by Jollu Emil on 11.07.2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long int n, x, t;
    cin >> n >> x >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<long long int, long long int>> mapper;
    for (int i = 0; i < n; i++) {
        mapper.push_back(make_pair(i + 1, abs(a[i] - x)));
    }
    sort(mapper.begin(), mapper.end(), [](const pair<long long int, long long int> &a, const pair<long long int, long long int> &b) {
        return a.second < b.second;
    });
    vector<long long int> ids;
    for (int i = 0; i < n; i++) {
        t -= mapper[i].second;
        if (t >= 0) {
            ids.push_back(mapper[i].first);
        } else {
            break;
        }
    }
    cout << ids.size() << endl;
    for (int id : ids) {
        cout << id << " ";
    }
    cout << endl;
    return 0;
}