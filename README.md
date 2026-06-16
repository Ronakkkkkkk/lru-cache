# LRU Cache - Systems Level Implementation

A clean and efficient implementation of an **LRU (Least Recently Used) Cache** in C++ using a Hash Map and Doubly Linked List to achieve O(1) time complexity for both `get` and `put` operations.

The project demonstrates core system design concepts including caching strategy, memory management, and efficient data structure usage.

---

## Overview

The LRU Cache is a fixed-capacity data structure that removes the least recently used item when the cache is full.

This implementation focuses on:
- Constant time operations
- Clean modular C++ design
- Real-world cache eviction behavior

---

## Features

- O(1) `get` operation
- O(1) `put` operation
- Automatic eviction of least recently used element
- Doubly Linked List for usage ordering
- Hash Map for fast key lookup
- Modular C++ design (header + source separation)
- Interview and system-design friendly implementation

---

## Architecture
┌──────────────────────┐
│ Client Code │
└──────────┬───────────┘
│ get / put
▼
┌──────────────────────┐
│ LRU Cache │
└──────────┬───────────┘
│
┌───────┴────────┐
│ │
▼ ▼
Hash Map Doubly Linked List
(O(1) lookup) (recency tracking)


---

## Tech Stack

### Language
- C++

### Data Structures
- unordered_map (Hash Map)
- Doubly Linked List

### Concepts
- Cache Design
- System Design Basics
- Pointer manipulation
- Memory management

---

## Project Structure


lru-cache/
│
├── include/
│ └── LRUCache.h
│
├── src/
│ └── LRUCache.cpp
│
├── examples/
│ └── main.cpp
│
├── CMakeLists.txt
├── README.md
└── .gitignore


---

## How It Works

- HashMap stores `key → node pointer` for O(1) access
- Doubly Linked List maintains usage order
- On `get(key)`:
  - If key exists → move node to front
  - Else → return -1
- On `put(key, value)`:
  - If key exists → update value and move to front
  - If capacity is full → remove least recently used node
  - Insert new node at front

---

## Complexity

| Operation | Time Complexity |
|----------|----------------|
| get      | O(1)           |
| put      | O(1)           |

---

## Build Instructions

```bash
mkdir build
cd build
cmake ..
cmake --build .
Run
./lru_cache.exe
Example Output
Put (1, 10)
Put (2, 20)
Get (1): 10
Put (3, 30) -> evicts LRU (key 2)
Get (2): -1
Get (3): 30
Get (1): 10
Key Takeaways
Efficient caching using hashing + linked list
Real-world eviction policy (LRU)
Clean separation of concerns in C++
Low-level memory handling with pointers
System design fundamentals
Author

Ronak Sharma
GitHub: https://github.com/Ronakkkkkkk