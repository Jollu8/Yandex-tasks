//
// Created by Jollu Emil on 11.07.2023.
//
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <functional>
#include <list>


template<typename Key, typename T>
class HashMap {
    std::vector<std::list<std::pair<Key, T>>> buckets;
    std::hash<Key> hash_function;
    size_t num_buckets;
public:
    HashMap(size_t num_buckets_ = 10) : num_buckets(num_buckets_) {
        buckets.resize(num_buckets_);
    }
    void put(const Key&key, const T&value = 0) {
        size_t bucket_index = hash_function(key) % num_buckets;
        for(auto &element : buckets[bucket_index]) {
            if(element.first == key) {
                element.second = value;
                return;
            }
        }
        buckets[bucket_index].push_back({key, value});
    }
    T get(const Key&key){
        size_t bucket_index = hash_function(key)%num_buckets;
        for(auto &element : buckets[bucket_index]) {
            if(element.first == key) return element.second;
        }
        return NULL;
    }

    void delete_(const Key&key) {
        size_t bucket_index = hash_function(key) % num_buckets;
        auto it = std::find_if(buckets[bucket_index].begin(), buckets[bucket_index].end(), [&](auto &element){
            return element.first == key;
        });
        if(it != buckets[bucket_index].end()) buckets[bucket_index].erase(it);
    }

};


int main() {
    HashMap<int, int> myMap;
    myMap.put(10);
    std::cout << std::boolalpha << myMap.get(1) << std::endl;
    myMap.put(1, 10);
    myMap.put(2,4);
    std::cout << myMap.get(1) << std::endl;
    std::cout << myMap.get(2) << std::endl;
    myMap.delete_(2);
    std::cout << myMap.get(2) << std::endl;
    myMap.put(1,5);
    std::cout << myMap.get(1) << std::endl;
    myMap.delete_(2);
}