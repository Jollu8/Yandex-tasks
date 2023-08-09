//
// Created by Jollu Emil on 26.07.2023.
//

#include <iostream>
#include <sstream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::string str;
    std::cin.ignore();
    getline(std::cin, str);
    str.resize(n);
    std::stringstream ss(std::move(str));
    std::string temp;
    int count = 0;
    while (ss >> temp) {
        if (temp.size() > count) count = temp.size();
    }
    std::cout << count;
}
