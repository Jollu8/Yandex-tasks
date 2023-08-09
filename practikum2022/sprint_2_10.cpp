#include <stack>
#include <iostream>
#include <string>

using namespace std;
int main ( ) {
    std::string expr;
    getline(cin, expr);
    stack<char>temp;
    for (int i = 0; i < expr.length(); i++)
    {
        if (temp.empty())
        {
            temp.push(expr[i]);
        }
        else if ((temp.top() == '(' && expr[i] == ')') ||
                 (temp.top() == '{' && expr[i] == '}') ||
                 (temp.top() == '[' && expr[i] == ']'))
        {
            temp.pop();
        }
        else
        {
            temp.push(expr[i]);
        }
    }
    std::cout << boolalpha << ((temp.empty()) ? true : false);
}
