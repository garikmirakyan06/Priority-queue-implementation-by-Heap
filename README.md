# Priority Queue Implementation

This is a custom implementation of a priority queue container adaptor in C++ using a binary heap. It supports both **max-heap** and **min-heap** functionality by using comparators (`std::greater` and `std::less`).
```cpp
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::greater<T>

> class Priority_queue;
```

## Features
- **Max-Heap** (default behavior) or **Min-Heap** using a comparator.
- Operations: `push`, `pop`, `top`, `size`, `empty`.
- by default uses std::vector container.  
- Implements heapify operations (`heapify_up` and `heapify_down`) for maintaining heap property.
- **Customizable container**: You can use any container that supports following functions (can use std::deque):
  - `empty()`
  - `size()`
  - `operator[]()`
  - `push_back()`
  - `pop_back()`

## Usage
```bash

cd scripts

./docker_install.sh # if dont have docker installed

./docker_run.sh # to run docker

