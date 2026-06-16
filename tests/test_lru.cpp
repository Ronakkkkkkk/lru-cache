#include <iostream>
#include "../include/LRUCache.h"

void assertEqual(int got, int expected, const std::string& testName) {
    if (got == expected) {
        std::cout << "[PASS] " << testName << "\n";
    } else {
        std::cout << "[FAIL] " << testName
                  << " | Got: " << got
                  << " Expected: " << expected << "\n";
    }
}

int main() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    assertEqual(cache.get(1), 10, "Get existing key");

    cache.put(3, 30); // evicts key 2

    assertEqual(cache.get(2), -1, "Evicted key should return -1");
    assertEqual(cache.get(3), 30, "Get new key");
    assertEqual(cache.get(1), 10, "Old key still exists");

    std::cout << "Tests completed.\n";
    return 0;
}