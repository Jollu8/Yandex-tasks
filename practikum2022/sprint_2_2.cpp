//
// Created by Jollu Emil on 30.07.2023.
//
#include <iostream>
#include <vector>
#include <string_view>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <chrono>

#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <unordered_set>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int n, m, tmp;
    cin >> n >> m ;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(auto i = 0; i < n; i++)
        for(auto j = 0; j < m; j++) {
            cin >> tmp;
            matrix[i][j] = tmp;
        }

    vector<vector<int>> cur(m, vector<int>(n));
    for(auto i = 0; i < n; i++) {
        for(auto j = 0; j < m; j++) {
            cur[m - j - 1][i] = matrix[i][j];
        }
    }


    for(const auto col : cur) {
        for(auto row : col) {
            std::cout << row << " ";
        }
        std::cout << endl;
    }


}