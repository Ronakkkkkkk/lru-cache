# LRU Cache — C++ Implementation

A clean, efficient **Least Recently Used (LRU) Cache** in C++ achieving **O(1)** time complexity for both `get` and `put` operations, built on a hash map and doubly linked list.

---

## Table of Contents

- [Overview](#overview)
- [How It Works](#how-it-works)
- [Architecture](#architecture)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage & Example](#usage--example)
- [Complexity](#complexity)
- [Tech Stack](#tech-stack)
- [Key Takeaways](#key-takeaways)
- [Author](#author)

---

## Overview

An LRU Cache is a fixed-capacity data structure that automatically evicts the **least recently used** item when the cache reaches capacity. This implementation demonstrates core systems concepts including caching strategy, memory management, and efficient data structure design — commonly seen in operating systems, databases, and system design interviews.

---

## How It Works

The cache combines two data structures:

- **`unordered_map`** — maps each key to its corresponding list node for O(1) lookup
- **Doubly Linked List** — tracks usage order; most recently used nodes sit at the front, least recently used at the back

### `get(key)`
- Key exists → move its node to the front, return value
- Key missing → return `-1`

### `put(key, value)`
- Key exists → update value, move node to front
- Cache full → remove the node at the back (LRU), insert new node at front
- Otherwise → insert new node at front

---

## Architecture

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
```

---

## Project Structure

```
lru-cache/
├── include/
│   └── LRUCache.h        # Class declaration
├── src/
│   └── LRUCache.cpp      # Core implementation
├── examples/
│   └── main.cpp          # Usage examples
├── CMakeLists.txt
├── README.md
└── .gitignore
```

---

## Getting Started

### Prerequisites

- C++11 or later
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

## Complexity

| Operation | Time | Space |
|-----------|------|-------|
| `get`     | O(1) | —     |
| `put`     | O(1) | —     |
| Overall   | —    | O(n)  |

`n` = cache capacity

---

## Tech Stack

- **Language:** C++11
- **Data Structures:** `std::unordered_map`, custom doubly linked list
- **Build System:** CMake
- **Concepts:** Cache design, pointer manipulation, memory management

---

## Key Takeaways

- Combines hashing and linked list to achieve constant-time cache operations
- Demonstrates a real-world eviction policy used in CPUs, browsers, and databases
- Clean separation of concerns via header/source split
- Low-level memory management with raw pointers — no external dependencies

---

## Author

**Ronak Sharma**
GitHub: [@Ronakkkkkkk](https://github.com/Ronakkkkkkk)