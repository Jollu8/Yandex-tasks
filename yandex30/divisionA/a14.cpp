#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    n++;
    vector<long int> jollu(n);
    for (int i = 1; i < n; i++) {
        cin >> jollu[i];
    }
    stack<pair<long int, long int>> stack;
    stack.push(make_pair(jollu[1], 1));
    vector<long int> rside(n, 0);
    vector<long int> lside(n, 0);
    for (int i = 2; i < n; i++) {
        while (!stack.empty() && stack.top().first > jollu[i]) {
            rside[stack.top().second] = i - 1;
            stack.pop();
        }
        stack.push(make_pair(jollu[i], i));
    }
    while (!stack.empty()) {
        rside[stack.top().second] = n - 1;
        stack.pop();
    }
    stack.push(make_pair(jollu[n - 1], n - 1));
    for (int i = n - 2; i > 0; i--) {
        while (!stack.empty() && stack.top().first > jollu[i]) {
            lside[stack.top().second] = i + 1;
            stack.pop();
        }
        stack.push(make_pair(jollu[i], i));
    }
    while (!stack.empty()) {
        lside[stack.top().second] = 1;
        stack.pop();
    }
    long int ans = 0;
    for (int i = 1; i < n; i++) {
        long int s = jollu[i] * (rside[i] - lside[i] + 1);
        ans = max(ans, s);
    }
    cout << ans << endl;
}
