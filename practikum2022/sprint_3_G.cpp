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
    auto colors = inputVec(std::cin, n);
    int pink = 0, yellow = 0, red = 0;
    for (auto i: colors) {
        switch (i) {
            case 0:
                ++pink;
                break;
            case 1:
                ++yellow;
                break;
            case 2:
                ++red;
                break;
        }
    }

    std::vector<int> res;
    res.insert(res.end(), pink, 0);
    res.insert(res.end(), yellow, 1);
    res.insert(res.end(), red, 2);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));


}