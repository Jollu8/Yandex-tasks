#include <iostream>
#include <vector>
#include <string_view>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <chrono>

#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <unordered_set>
#include <queue>
#include <cmath>

using namespace std;


template<typename T>
class Deque {
    struct Node {
        T data;
        Node *next;
        Node *prev;

        Node(T data_) : data(data_), next(nullptr), prev(nullptr) {}


    };

    Node *front, *back;

public:

    Deque() : front(nullptr), back(nullptr) {}

    ~Deque() {
        while (front) {
            Node *tmp = front;
            front = front->next;
            delete tmp;
        }
    }

    void push_front(T data) {
        Node *newNode = new Node(data);
        if (!front) {
            front = back = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void push_back(T data) {
        Node *newNode = new Node(data);
        if (!back) front = back = newNode;
        else {
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
        }
    }

    T pop_front() {
        if(front) {
            Node *tmp = front;
            if(front == back)
                front = back = nullptr;

            else {
                front = front->next;
                front->prev = nullptr;
            }
            T cur = tmp->data;
            delete tmp;
            return cur;
        }
    }

    T pop_back() {
        T cur;
        if(back) {
            Node *tmp = back;
            if(front == back) front = back = nullptr;
            else{
                back = back->prev;
                back->next = nullptr;
            }
            cur = tmp->data;
            delete tmp;

        }
        return cur;
    }

    template<typename Z>
    friend  ostream &operator << (ostream os, Z z) {
        os <<z;
    }
};

int main() {
    Deque<int> deque_;
    int n, m;
    cin >> n >> m;
    deque_.push_front(861);
    deque_.push_front(-819);
    std::cout << deque_.pop_back() << endl;
    std::cout << deque_.pop_back() << endl;


}