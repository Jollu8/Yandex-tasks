//
// Created by Jollu Emil on 31.07.2023.
//

#include <iostream>
#include <string>
#include <utility>

struct Node {
    std::string value;
    Node*next;
    Node(const std::string  value_, Node*next_) : value(value_), next(next_) {}
};

void solution(Node*head) {
    Node*tmp = head;
    while (tmp != nullptr) {
        std::cout << tmp->value << '\n';
        tmp = tmp->next;
    }
}