//
// Created by Jollu Emil on 25.07.2023.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>

int main() {
    int n, m, x, y, z;

    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> matrix[i][j];

    std::cin >> x >> y;
    std::vector<int> res;
    if (x > 0) res.emplace_back(matrix[x - 1][y]);
    if (x < n - 1) res.emplace_back(matrix[x + 1][y]);
    if (y > 0) res.emplace_back(matrix[x][y - 1]);
    if (y < m - 1) res.emplace_back(matrix[x][y + 1]);
    for(auto i : res)std::cout << i << " ";
}