#include <iostream>
#include <cassert>
#include "../include/LRUCache.h"

void test_basic_get_put() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    assert(cache.get(1) == 10);  // should hit
    std::cout << "[PASS] Get existing key\n";
}

void test_eviction() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30); // evicts key 1

    assert(cache.get(1) == -1);  // should be evicted
    std::cout << "[PASS] Evicted key should return -1\n";
}

void test_update_and_order() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cache.get(1);     // makes 2 LRU
    cache.put(3, 30);  // evicts 2

    assert(cache.get(2) == -1);
    assert(cache.get(1) == 10);
    assert(cache.get(3) == 30);

    std::cout << "[PASS] LRU order maintained correctly\n";
}

int main() {
    test_basic_get_put();
    test_eviction();
    test_update_and_order();

    std::cout << "All tests passed.\n";
    return 0;
}