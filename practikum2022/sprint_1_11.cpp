//
// Created by Jollu Emil on 29.07.2023.
//
#include <iostream>
#include <vector>
#include <string_view>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <chrono>

#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <unordered_set>
#include <queue>
#include <cmath>

using namespace std;



int main(){
    int n;
    cin >> n;
    bool res = true;
    if(n == 1) res = false;

    int x = log10(n) / log10(4);
    if(pow(4, x) == n) res = true;
    else res = false;

    std::cout << boolalpha << res;
}
