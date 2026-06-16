#include "LRUCache.h"
#include <mutex>
// ---------------- Node constructor ----------------
LRUCache::Node::Node(int k, int v) {
    key = k;
    value = v;
    prev = nullptr;
    next = nullptr;
}

// ---------------- Constructor ----------------
LRUCache::LRUCache(int capacity) {
    this->capacity = capacity;

    head = new Node(-1, -1);
    tail = new Node(-1, -1);

    head->next = tail;
    tail->prev = head;
}

// ---------------- Add node right after head (MRU position) ----------------
void LRUCache::addToFront(Node* node) {
    node->next = head->next;
    node->prev = head;

    head->next->prev = node;
    head->next = node;
}

// ---------------- Remove node from DLL ----------------
void LRUCache::removeNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

// ---------------- Move node to front (mark as recently used) ----------------
void LRUCache::moveToFront(Node* node) {
    removeNode(node);
    addToFront(node);
}

// ---------------- Remove least recently used node ----------------
LRUCache::Node* LRUCache::removeLRU() {
    Node* lru = tail->prev;
    removeNode(lru);
    return lru;
}

// ---------------- GET operation ----------------
int LRUCache::get(int key) {
    std::lock_guard<std::mutex> lock(mtx);

    if (cache.find(key) == cache.end())
        return -1;

    Node* node = cache[key];

    moveToFront(node);

    return node->value;
}

// ---------------- PUT operation ----------------
void LRUCache::put(int key, int value) {
    std::lock_guard<std::mutex> lock(mtx);

    if (cache.find(key) != cache.end()) {
        Node* node = cache[key];
        node->value = value;
        moveToFront(node);
        return;
    }

    if ((int)cache.size() == capacity) {
        Node* lru = removeLRU();
        cache.erase(lru->key);
        delete lru;
    }

    Node* node = new Node(key, value);
    addToFront(node);
    cache[key] = node;
}