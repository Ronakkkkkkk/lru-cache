#pragma once

#include <unordered_map>
#include <mutex>
#include <iostream>

class LRUCache {
private:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v);
    };

    int capacity;
    std::unordered_map<int, Node*> cache;

    Node* head;
    Node* tail;

    std::mutex mtx;

    size_t hits = 0;
    size_t misses = 0;

    void addToFront(Node* node);
    void removeNode(Node* node);
    void moveToFront(Node* node);
    Node* removeLRU();

public:
    explicit LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
    void printStats();
    ~LRUCache();
};