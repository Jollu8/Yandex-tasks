#include <iostream>
#include <algorithm>

int main() {
    long int arr[3];
    std::cin >> arr[0] >> arr[1] >> arr[2];
    auto res = 0;
    for (auto i = 0; i < 3; i++)
        if (arr[i] & 1) res++;
    std::cout << ((res == 1 || res == 3) ? "WIN" : "FAIL");
}