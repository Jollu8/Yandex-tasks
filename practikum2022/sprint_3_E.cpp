#include <iostream>
#include <vector>


std::vector<int> inputVec(std::istream& is, int n) {
    std::vector<int> temp;
    int num;
    while ( n > 0 && is >> num) {
        temp.emplace_back(num);
        --n;
    }
    return temp;
}

int inputInt(std::istream&is) {
    int temp;
    is >> temp;
    return temp;
}

int main() {
    int n = inputInt(std::cin);
    int k = inputInt(std::cin);
    auto houses = inputVec(std::cin, n);
    std::sort(houses.begin(), houses.end());
    int res = 0;
    for(auto i : houses) {
        if(k  - i < 0) break;
        k -= i;
        ++res;
    }

    std::cout << res;

}