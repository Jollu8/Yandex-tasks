#include <iostream>
#include <string>
#include <utility>

struct Node {
    std::string value;
    Node*next;
    Node*prev;
    Node() = default;
    Node(const std::string&value_, Node*next_, Node*prev_) : value(value_), next(next_), prev(prev_) {}
};

void add_Node(Node* head) {

    for(auto i =0 ; i < 10; i++) {
        Node * newNode = new Node{};
        newNode->value = std::to_string(i);
        newNode->next = head;
        newNode->prev = nullptr;
        if(head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;


    }
}

Node * solution(Node*head) { // reverse double Node
    Node*current = head;
    Node*temp = nullptr;

    while(current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp != nullptr) head = temp->prev;
    return head;
}
