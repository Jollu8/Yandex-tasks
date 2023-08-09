#include <iostream>
#include <queue>
#include <string>


class MyQueueSized {
    std::queue<int> q;
    const unsigned int s;
public:
    MyQueueSized(uint size_) : s(size_) {}

    void push(int x) {
        if (q.size()  == s) {
            std::cout << "error\n";
            return;
        }
        q.push(x);

    }

    void pop() {
        int res = q.front();
        q.pop();
        std::cout << res << std::endl;
    }

    void peek() {
        std::cout << q.front() << std::endl;
    }

    void size() {
        std::cout << s << std::endl;
    }
};

int main() {
    MyQueueSized myQueueSized(1);
    myQueueSized.push(1);
    myQueueSized.size();
    myQueueSized.push(3);
    myQueueSized.size();
    myQueueSized.push(1);
    myQueueSized.pop();
    myQueueSized.push(1);
    myQueueSized.pop();
    myQueueSized.push(3);
    myQueueSized.push(3);
}
