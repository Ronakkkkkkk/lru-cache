#include "LRUCache.h"

// ---------------- Node constructor ----------------
LRUCache::Node::Node(int k, int v) {
    key = k;
    val = v;
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
    if (cache.find(key) == cache.end()) {
        return -1;
    }

    Node* node = cache[key];
    moveToFront(node);

    return node->val;
}

// ---------------- PUT operation ----------------
void LRUCache::put(int key, int value) {
    // If key already exists, update and move to front
    if (cache.find(key) != cache.end()) {
        Node* node = cache[key];
        node->val = value;
        moveToFront(node);
        return;
    }

    // If capacity full, remove LRU
    if ((int)cache.size() == capacity) {
        Node* lru = removeLRU();
        cache.erase(lru->key);
        delete lru;
    }

    // Insert new node
    Node* node = new Node(key, value);
    addToFront(node);
    cache[key] = node;
}