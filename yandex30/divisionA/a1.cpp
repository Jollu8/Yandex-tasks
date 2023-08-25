//
// Created by Jollu Emil on 11.07.2023.
//
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

string inputString(istream&is) {
    string tmp;
    is >> tmp;
    return tmp;
}

int main() {
    auto first = inputString(cin);
    auto second = inputString(cin);
    hash<string> f1,f2;
    auto first_hash = f1(first);
    string second_hash = ;

}