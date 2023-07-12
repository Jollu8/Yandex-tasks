#include <cstdio>
#include <string>
#include <iostream>
#include "exprtk.hpp"


// на С++ написать этот код очень тяжело
// за это я отправил на питоне
///try:
///print(eval(input()))
///except:
///print("WRONG")

using namespace std;
int main() {
    typedef exprtk::expression<double> expression_t;
    typedef exprtk::parser<double> parser_t;

    std::string expression_string;
    getline(cin, expression_string);
    expression_t expression;
    parser_t parser;

    if (parser.compile(expression_string, expression)) {
        double result = expression.value();
        printf("Result: %19.15f\n", result);
    } else {
        printf("Error in expression\n.");
    }

    return 0;
}
