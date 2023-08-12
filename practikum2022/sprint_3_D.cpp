#include <iostream>
#include <set>

int inputInt(std::istream &is) {
    int n;
    is >> n;
    return n;
}

int main() {
    int count = 0;
    int n = inputInt(std::cin);
    std::multiset<int> children;

    for (auto i = 0; i < n; ++i)
        children.insert(inputInt(std::cin));

    int m = inputInt(std::cin);
    for (auto i = 0; i < m; ++i) {
        auto temp = inputInt(std::cin);
        if (children.contains(temp)) {
            count++;
            children.erase(temp);
        }
    }

    std::cout << count;


}