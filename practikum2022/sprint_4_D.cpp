#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string > inputVecStr(std::istream&is, int n) {
    std::vector<std::string > tmp;
    tmp.reserve(n);
    std::string str;
    while (n > 0) {
        getline(is, str);
        tmp.emplace_back(std::move(str));
        --n;
    }
    return tmp;
}

int inputInt(std::istream&is) {
    int tmp;
    is >> tmp;
    return tmp;
}

int main() {
    int n = inputInt(std::cin);
    auto words = inputVecStr(std::cin, n);
    std::vector<std::string > ans;
    std::unique_copy(words.begin(), words.end(), std::back_inserter(ans));
    for(auto &it: ans) std::cout << it << std::endl;
}