#include <iostream>
#include <deque>

using namespace std;

void equalize(deque<int> &d1, deque<int> &d2) {
    while (d1.size() < d2.size()) {
        d1.push_back(d2.front());
        d2.pop_front();
    }
}

int main() {
    int n;
    cin >> n;
    deque<int> d1, d2;
    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;
        if (op == '+') {
            int x;
            cin >> x;
            d2.push_back(x);
            equalize(d1, d2);
        } else if (op == '*') {
            int x;
            cin >> x;
            d2.push_front(x);
            equalize(d1, d2);
        } else if (op == '-') {
            cout << d1.front() << endl;
            d1.pop_front();
            equalize(d1, d2);
        }
    }
    return 0;
}
