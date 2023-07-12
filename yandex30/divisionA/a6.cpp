#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> stack;
    for (int i = 0; i < N; i++) {
        vector<int> lj(2);
        cin >> lj[0] >> lj[1];
        auto ix = lower_bound(stack.begin(), stack.end(), lj);
        stack.insert(ix, lj);
        ix = find(stack.begin(), stack.end(), lj);
        if (!stack.empty()) {
            while (ix + 1 < stack.end() && (ix + 1)->at(0) <= lj[1]) {
                stack.erase(ix + 1);
            }
            while (ix - 1 >= stack.begin() && (ix - 1)->at(1) >= lj[0]) {
                stack.erase(ix - 1);
                ix--;
            }
        }
    }
    cout << stack.size() << endl;
    return 0;
}
