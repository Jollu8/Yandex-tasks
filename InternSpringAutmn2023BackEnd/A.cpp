//
// Created by Jollu Emil on 11.07.2023.
//

#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> alphabet(N);
    for (int i = 0; i < N; i++) {
        std::cin >> alphabet[i];
    }
    std::vector<int> rows(N);
    for (int i = 0; i < N; i++) {
        std::cin >> rows[i];
    }
    int K;
    std::cin >> K;
    std::vector<int> string(K);
    for (int i = 0; i < K; i++) {
        std::cin >> string[i];
    }

    std::unordered_map<int, int> mapper;
    for (int i = 0; i < N; i++) {
        mapper[alphabet[i]] = rows[i];
    }

    int counter = 0;
    for (int i = 0; i < K - 1; i++) {
        counter += int(mapper[string[i]] != mapper[string[i+1]]);
    }
    std::cout << counter << std::endl;

    return 0;
}