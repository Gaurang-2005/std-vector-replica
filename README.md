# Custom C++ Vector (STL-like Implementation)

A from-scratch implementation of a dynamic array similar to `std::vector`, built to understand memory management, move semantics, and container design in modern C++.

---

## 🚀 Features

* Dynamic resizing with **amortized O(1) push_back**
* Contiguous memory storage
* Full **Rule of 5** implementation:

  * Copy constructor
  * Copy assignment (exception-safe)
  * Move constructor (`noexcept`)
  * Move assignment (`noexcept`)
  * Destructor
* Bounds-checked element access using `operator[]`
* Support for:

  * Primitive types (`int`, etc.)
  * Complex types (`std::string`, etc.)

---

## 🧠 Concepts Covered

This project demonstrates:

* Manual memory management using `new[]` / `delete[]`
* Deep copy vs shallow copy
* Move semantics (`std::move`)
* Exception safety (strong guarantee via copy-and-swap)
* Amortized time complexity
* Resource ownership and RAII

---

## 📂 Project Structure

```
.
├── vector.hpp   # Implementation of custom vector
├── test.cpp     # Test cases and usage examples
```

---

## 🛠️ Build & Run

### Compile:

```bash
g++ -std=c++20 -Wall -Wextra -g test.cpp -o test.exe
```

### Run:

```bash
./test.exe
```

---

## 📈 Example Usage

```cpp
vector<int> v;

for (int i = 0; i < 10; i++) {
    v.push_back(i);
}

for (unsigned i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
}
```

---

## 🔍 Stress Testing

The implementation has been tested with:

* Thousands of insertions
* Capacity growth verification
* Copy and move operations
* Exception handling (out-of-bounds access)

---

## ⚠️ Limitations (Compared to std::vector)

This is a learning-focused implementation. It does **not** include:

* Iterators (`begin()`, `end()`)
* `reserve`, `clear`, `pop_back`
* Allocator support
* `emplace_back` (perfect forwarding)

---

## 🎯 Motivation

The goal of this project was not just to re-create `std::vector`, but to deeply understand:

> How real-world containers manage memory, ownership, and performance.

---

## 📌 Future Improvements

* Add `emplace_back` with perfect forwarding
* Implement iterators
* Add `reserve()` and `pop_back()`
* Improve API parity with `std::vector`

---

## 💡 Key Takeaway

> This project builds the foundation for understanding how high-performance C++ containers are implemented under the hood.

---

## 🧑‍💻 Author

Gaurang Gupta
