//
// Created by Jollu Emil on 31.07.2023.
//
#include <iostream>
#include <string>
#include <utility>

struct Node {
    std::string value;
    Node*next;
    Node(const std::string&value_, Node*next_) : value(value_), next(next_) {}
};

int solution(Node*head, const std::string& elem) {
    unsigned int index = 0;
    Node*tmp = head;
    while (tmp != nullptr) {
        if(tmp->value == elem) return index;
        else {
            index++;
            tmp = tmp->next;
        }
    }
    return -1;
}