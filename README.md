# LRU Cache — C++ Implementation

A clean, efficient **Least Recently Used (LRU) Cache** in C++ achieving **O(1)** time complexity for both `get` and `put` operations, built on a hash map and doubly linked list.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [How It Works](#how-it-works)
- [Architecture](#architecture)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage & Example](#usage--example)
- [Cache Metrics](#cache-metrics)
- [Benchmark](#benchmark)
- [Complexity](#complexity)
- [Tech Stack](#tech-stack)
- [Key Takeaways](#key-takeaways)
- [Author](#author)

---

## Overview

An LRU Cache is a fixed-capacity data structure that automatically evicts the **least recently used** item when the cache reaches capacity. This implementation demonstrates core systems concepts including caching strategy, memory management, and efficient data structure design — commonly seen in operating systems, databases, and system design interviews.

---

## Features

- O(1) get operation
- O(1) put operation
- Automatic LRU eviction
- Custom doubly linked list implementation
- Hash map based indexing
- Thread-safe cache operations using `std::mutex`
- Cache performance metrics (hits, misses, hit rate)
- Unit test suite
- Benchmarking utility
- Proper memory cleanup via destructor
- CMake build system

---

## How It Works

The cache maintains two synchronized data structures:

### 1. Access Path (Hash Map)
- Maps `key → node pointer`
- Eliminates search time

### 2. Usage Tracking (Doubly Linked List)
- Every access updates node position
- Ensures most recently used items are always at the front

### Operations

#### GET
- If key exists:
  - Move node to front (mark as recently used)
  - Return value
- Else:
  - Return -1

#### PUT
- If key exists:
  - Update value
  - Move node to front
- If capacity is full:
  - Remove node from tail (LRU eviction)
  - Delete from hash map
- Insert new node at front

---

## Architecture

This cache is designed as an in-memory eviction system similar to those used in:
- database buffer caches
- Redis-like in-memory storage systems
- operating system page replacement strategies

### Internal Design

The system is composed of two tightly coupled components:

- **Hash Map (Index Layer)**
  - Provides O(1) access to cache nodes via key lookup

- **Doubly Linked List (Eviction Layer)**
  - Maintains access order
  - Front → Most Recently Used
  - Back → Least Recently Used (eviction target)

### Data Flow

```
Client Request → Cache Interface → Index Layer + Eviction Layer → Updated State
```

```
         Client Code
              │
         get / put
              │
        ┌─────▼──────┐
        │  LRU Cache  │
        └──────┬──────┘
               │
       ┌───────┴────────┐
       ▼                ▼
   Hash Map       Doubly Linked List
  (O(1) lookup)   (recency ordering)
       │                │
       │         [MRU] ←→ ... ←→ [LRU]
       │          front            back
       └──────────────┘
         synchronized
```

---

## Project Structure

```text
lru-cache/
├── include/
│   └── LRUCache.h
├── src/
│   └── LRUCache.cpp
├── examples/
│   └── main.cpp
├── tests/
│   └── test_lru.cpp
├── benchmarks/
│   └── benchmark.cpp
├── CMakeLists.txt
├── LICENSE
├── README.md
└── .gitignore
```

---

## Getting Started

### Prerequisites

- Modern C++ (C++17 recommended)
- CMake 3.10+

### Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Run

```bash
./lru_cache
```

---

## Usage & Example

```cpp
LRUCache cache(2); // capacity = 2

cache.put(1, 10);
cache.put(2, 20);
cache.get(1);      // returns 10  — key 1 is now most recently used
cache.put(3, 30);  // evicts key 2 (LRU)
cache.get(2);      // returns -1  — key 2 was evicted
cache.get(3);      // returns 30
cache.get(1);      // returns 10
```

**Expected output:**

```
Put (1, 10)
Put (2, 20)
Get (1): 10
Put (3, 30) → evicts LRU (key 2)
Get (2): -1
Get (3): 30
Get (1): 10
```

---

## Cache Metrics

The cache tracks runtime statistics:

- Cache Hits
- Cache Misses
- Hit Rate

Example:

```text
--- Cache Stats ---
Hits   : 3
Misses : 1
Hit Rate: 0.75
```

---

## Benchmark

A simple benchmark is included to measure cache throughput.

Example run:

```text
Operations: 200000
Time: 24 ms
Ops/sec: 8.33e+06
```

This demonstrates millions of cache operations per second while maintaining O(1) access characteristics.

---

## Complexity

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| get       | O(1)           | O(1)             |
| put       | O(1)           | O(1)             |

Overall space usage is O(n), where n is cache capacity.

---

## System Design Perspective

This implementation reflects key design principles used in production systems:

### 1. O(1) Efficiency Design
Trade memory for speed using dual data structures.

### 2. Eviction Policy (LRU)
Ensures memory remains bounded under constrained resources.

### 3. Separation of Concerns
- Indexing (Hash Map)
- Ordering (Linked List)
- API Layer (Cache Interface)

### 4. Real-world Applications
- CPU cache memory
- Database query caching
- Web browser caching
- Distributed cache systems (Redis-like behavior)

---

## Tech Stack

- Language: C++17
- Data Structures:
  - `std::unordered_map`
  - Custom Doubly Linked List
- Concurrency:
  - `std::mutex`
- Build System:
  - CMake
- Testing:
  - Custom unit tests
- Benchmarking:
  - Performance measurement utility

---

## Key Takeaways

- Achieves O(1) cache operations through combined hash map and linked list design
- Implements real-world LRU eviction policy
- Supports thread-safe access using mutex locking
- Includes cache performance metrics and monitoring
- Provides unit tests and benchmarking utilities
- Demonstrates manual memory management and resource cleanup
- Mirrors concepts used in operating systems, databases, browsers, and distributed caches

---

## Author

**Ronak Sharma**
GitHub: [@Ronakkkkkkk](https://github.com/Ronakkkkkkk)