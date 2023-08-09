#include <iostream>
#include <vector>
#include <algorithm>

class StackMax {
    std::vector<int> container;
    int max;

public:
    StackMax (): max(INT_MIN){}
    void push(int x) {
        if(max < x) max = x;
        container.push_back(x);
    }
    void pop() {
        if(container.empty()) {
            std::cout << "error\n";
            return;
        }
        if(max == container.back()) {
            container.pop_back();
            auto res = std::max_element(container.begin(), container.end());
            if(res != container.end()) {
                max = *res;
            }else max = INT_MIN;
        }
    }
    void get_max () {
        if(container.empty()){
            std::cout  << "None\n";
            return;
        }
        std::cout << max << std::endl;

    }
};

int main() {
    StackMax stackMax;
    stackMax.get_max();
    stackMax.push(7);
    stackMax.pop();
    stackMax.push(-2);
    stackMax.push(-1);
    stackMax.pop();
    stackMax.get_max();
    stackMax.get_max();
}