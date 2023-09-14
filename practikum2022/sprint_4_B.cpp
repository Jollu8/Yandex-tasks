#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

string inputString(istream &is) {
    string tmp;
    is >> tmp;
    return tmp;
}

int main() {
    auto first = inputString(cin);
    auto second = inputString(cin);
    hash<string> f1, f2;
    auto first_hash = f1(first);
    auto second_hash = f2(second);
    std::cout << boolalpha << (first_hash == second_hash);

}