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
    auto students = inputVec(std::cin, n);
    auto ID = inputInt(std::cin);
    std::unordered_map<int, int>tmp;
    for(auto i : students) {
        if(i <= ID) ++tmp[i];
    }
    std::vector<int>res;
    for(auto &it: tmp) {
        res.emplace_back(it.first);
    }
    std::sort(res.begin(), res.end());
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout , " "));


}