//
// Created by Jollu Emil on 29.07.2023.
//
#include <stdio.h>
#include <iostream>

//void convertToBinary(unsigned int n)
//{
//    if (n / 2 != 0) {
//        convertToBinary(n / 2);
//    }
//    printf("%d", n % 2);
//}
//int main() {
//    int dec;
//    std::cin >> dec;
//    convertToBinary(dec);
//
//}


#include <iostream>
#include <climits>

int main() {
    unsigned int number = 3;
    unsigned int bit = UINT_MAX/2 + 1;
    bool flag = false;

    while (bit) {
        if (number&bit) {
            std::cout << 1;
            flag = true;
        }
        else {
            if (flag) std::cout << 0;
        }
        bit = bit >> 1;
    }
}