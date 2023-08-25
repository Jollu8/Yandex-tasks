#include <iostream>
#include <vector>


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
    auto digits = inputVec(std::cin, n);
    std::sort(digits.begin(), digits.end(), [](auto a, auto b) {
        int temp_a = a;
        int temp_b = b;
        while (temp_a >= 10) {
            temp_a /= 10;
        }
        while (temp_b >= 10) {
            temp_b /= 10;
        }
        return temp_a > temp_b;

    });
    std::copy(digits.begin(), digits.end(), std::ostream_iterator<int>(std::cout));


}