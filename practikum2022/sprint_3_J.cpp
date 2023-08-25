#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


std::vector<int> inputVec(std::istream &is, int n) {
    std::vector<int> temp;
    int num;
    while (n > 0 && is >> num) {
        temp.emplace_back(num);
        --n;
    }
    return temp;
}

int inputInt(std::istream &is) {
    int temp;
    is >> temp;
    return temp;
}

int main() {
    int n = inputInt(std::cin);
    auto k = inputVec(std::cin, n);

    for (auto i = 0; i < n; ++i) {
        bool change = false;
        for (auto j = 0; j < n - 1; ++j) {
            if (k[j] > k[j + 1]) {
                std::swap(k[j], k[j + 1]);
                change = true;
            }

        }
        if (change) {
            std::copy(k.begin(), k.end(), std::ostream_iterator<int>(std::cout, " "));
            std::cout << std::endl;
            change = false;
        }
    }

}

