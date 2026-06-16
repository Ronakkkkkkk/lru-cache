#include <iostream>
#include <chrono>
#include "../include/LRUCache.h"

int main() {
    const int N = 100000;

    LRUCache cache(1000);

    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < N; i++) {
        cache.put(i, i);
    }

    for(int i = 0; i < N; i++) {
        cache.get(i);
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(
            end - start);

    std::cout << "Operations: " << 2 * N << "\n";
    std::cout << "Time: " << duration.count() << " ms\n";

    double ops_per_sec =
        (2.0 * N * 1000) / duration.count();

    std::cout << "Ops/sec: "
              << ops_per_sec
              << "\n";
}