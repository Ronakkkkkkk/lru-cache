#include <iostream>
#include "LRUCache.h"

int main() {
    LRUCache cache(2);

    std::cout << "Put (1, 10)\n";
    cache.put(1, 10);

    std::cout << "Put (2, 20)\n";
    cache.put(2, 20);

    std::cout << "Get (1): " << cache.get(1) << "\n"; // should be 10

    std::cout << "Put (3, 30) -> evicts LRU (key 2)\n";
    cache.put(3, 30);

    std::cout << "Get (2): " << cache.get(2) << "\n"; // should be -1

    std::cout << "Get (3): " << cache.get(3) << "\n"; // should be 30

    std::cout << "Get (1): " << cache.get(1) << "\n"; // should be 10

    cache.printStats();

    return 0;
}