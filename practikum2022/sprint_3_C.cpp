#include <iostream>
#include <set>
#include <string>


std::string inputStr(std::istream& is) {
    std::string str;
    is >> str;
    return str;
}

int main() {
    std::string s = inputStr(std::cin);
    std::string t = inputStr(std::cin);
    int count = 0;
    for(auto i = 0; i < t.size() && count < s.size(); i++){
        if(s[count] == t[i]) count++;
    }

    std::cout << std::boolalpha << (count == s.size());

}