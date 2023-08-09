#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>

void genParenthesis(int n, int open, int close, std::string s, std::vector<std::string> &ans) {
    if (open == n && close == n) {
        ans.emplace_back(s);
        return;
    }

    if (open < n)genParenthesis(n, open+1, close , s + "(", ans);
    if (close< open) genParenthesis(n, open, close + 1, s + ")", ans);
}

int main() {
    std::vector<std::string>ans;
    int n;
    std::cin >> n;

    genParenthesis( n , 0, 0, "", ans);
    std::copy(ans.begin(), ans.end(), std::ostream_iterator<std::string_view>(std::cout, "\n"));
    std::cout << '\n';
    return 0;


}