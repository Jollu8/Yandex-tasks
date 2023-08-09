#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std::string_literals;
using namespace std;

string inputStr(istream &is) {
    string s;
    cin >> s;
    return s;

}



vector<string> solution(const string& digits, unordered_map<string, string> &numberRules) {
    if (digits.empty()) return {};

    vector<string> result;
    string words = numberRules[digits.substr(digits.size() - 1, 1)];
    vector<string> combinations = solution(digits.substr(0, digits.size() - 1), numberRules);

    if (!combinations.empty()) {
        for (const auto& combination: combinations) {
            for (char c: words) {
                result.push_back(combination + c);
            }
        }
    } else {
        for (char c: words) {
            result.emplace_back(1, c);
        }
    }return result;
}

int main() {
    unordered_map<string, string> numberRules{
            {"2", "abc"},
            {"3", "def"},
            {"4", "ghi"},
            {"5", "jkl"},
            {"6", "mno"},
            {"7", "pqrs"},
            {"8", "tuv"},
            {"9", "wxyz"}
    };

    auto input = inputStr(cin);
    auto res = solution(input, numberRules);
    copy(res.begin(), res.end(), ostream_iterator<string_view>(cout, "\n"));
    cout << endl;


}