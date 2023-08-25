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


double CalcMHWScore(std::vector<int> &scores) {
    size_t size = scores.size();

    if (size == 0) {
        return 0;  // Undefined, really.
    } else {
        sort(scores.begin(), scores.end());
        if (size % 2 == 0) {
            return ((double) scores[size / 2 - 1] + (double) scores[size / 2]) / 2;
        } else {
            return scores[size / 2];
        }
    }
}

int main() {
    int n = inputInt(std::cin);
    auto m = inputInt(std::cin);
    auto first = inputVec(std::cin, n);

    auto second = inputVec(std::cin, m);
    first.insert(first.end(), second.begin(), second.end());
    std::sort(first.begin(), first.end());
    auto res = CalcMHWScore(first);
    std::cout << res;


}
