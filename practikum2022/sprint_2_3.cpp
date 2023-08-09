//
// Created by Jollu Emil on 31.07.2023.
//
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluateRPN(string expr) {
    stack<int> s;
    for (int i = 0; i < expr.length(); i++) {
        if (isdigit(expr[i])) {
            s.push(expr[i] - '0');
        } else if (expr[i] != ' ') {
            int y = s.top();
            s.pop();
            int x = s.top();
            s.pop();
            if (expr[i] == '+') {
                s.push(x + y);
            } else if (expr[i] == '-') {
                s.push(x - y);
            } else if (expr[i] == '*') {
                s.push(x * y);
            } else if (expr[i] == '/') {
                s.push(x / y);
            }
        }
    }
    return s.top();
}

int main() {
    string expr ;
    getline(cin, expr);
    cout << evaluateRPN(expr) << endl;
    return 0;
}
