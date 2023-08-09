#include <iostream>
#include <sstream>
#include <algorithm>


int main() {
    int n;
    std::cin >> n;
    std::string words;
    std::cin.ignore();
    getline(std::cin, words);
    words.resize(n);

    int res = 0;
    std::stringstream ss(words);
    std::string temp;
    while (ss >> temp) {
        if(temp.size() > res) res = temp.size();
    }

    std::cout << res;


}