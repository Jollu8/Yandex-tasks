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
    auto days = inputVec(std::cin, n);
    auto s = inputInt(std::cin);
    auto first_res = std::lower_bound(days.begin(), days.end(), s);
    bool first_check = false;
    int first = -1;
    int second = -1;
    if(first_res != days.end()) {
        first = *first_res;
        first_check = true;

    }
    if(first_check) {
        auto second_res = std::lower_bound(days.begin(), days.end(), s*2);
        if(second_res != days.end()) {
            second = *second_res;
        }
    }
    std::cout << first << " " << second;

}