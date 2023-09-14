//
// Created by Jollu Emil on 08.09.2023.
//

#include <string>
#include <unordered_set>
#include <algorithm>
#include <iostream>

std::string inputStr(std::istream &is) {
    std::string tmp;
    is >> tmp;
    return std::move(tmp);
}

class Heap {
    std::vector<int> data;
    int heapSize;
    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if(left < heapSize && data[left] > data[i]) largest = left;
        if(right < heapSize && data[left] > data[largest]) largest = right;
        if(largest != i) {
            std::swap(data[i], data[largest]);
            heapify(largest);
        }
    }
public:
    Heap():heapSize(0) {}

    void push(int value) {
        if(heapSize >= data.size()) {
            data.emplace_back(0);
        }
        int i = ++heapSize;
        int parent = (i - 1) / 2;
        while (i > 0 && data[parent] < value) {
            data[i] = data[parent];
            i = parent;
            parent = (i - 1) / 2;

        }
        data[i] = value;
    }

    int maxHeap() {
        return data[0];
    }
    void deleteMax() {
        if(heapSize == 0) return;
        data[0] = data[--heapSize];
        heapify(0);
    }
};

int main() {
    Heap h;
    h.push(1);
    h.push(3);
    h.push(8);
    h.push(10);
    h.push(14);
    h.push(15);
    h.push(3);
    h.push(5);
    h.push(2);
    h.push(6);
    h.push(0);
    h.push(1);
    std::cout << h.maxHeap();


}