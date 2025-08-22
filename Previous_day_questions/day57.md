<h2 align="center">Day 57 (11/08/2025)</h2>

## 1. K Largest Elements
A problem that introduces heap-based selection algorithms and teaches efficient top-k finding techniques using priority queue data structures for optimal element retrieval and ranking operations.

Given an array and a number **k**, print the **k largest elements** using a heap-based approach. This operation is fundamental in **selection algorithms** and **ranking systems** where you need to **identify top performers** or **highest values** efficiently without full array sorting. The technique uses **min-heap of size k** to maintain the k largest elements seen so far, replacing smaller elements as larger ones are encountered. This concept is essential in **data analytics**, **recommendation systems**, and **performance monitoring** where finding top-k elements enables efficient ranking and selection without the overhead of complete sorting operations.

This teaches **heap-based selection algorithms** and **priority queue optimization techniques** that are essential for **top-k analysis and efficient element ranking operations**.

**Your task:** Implement min-heap based k-largest selection to efficiently identify top elements while maintaining optimal time and space complexity.

### Examples

**Input:**
```
arr = [1, 23, 12, 9, 30, 2, 50], k = 3
```
**Output:**
```
[50, 30, 23]
```

---

**Input:**
```
arr = [10, 15, 5], k = 2
```
**Output:**
```
[15, 10]
```

---

## 2. Is Array a Max Heap
A problem that demonstrates heap property validation and teaches structural verification algorithms using parent-child relationship checking for data structure integrity analysis.

Given an array, check if it **satisfies the max-heap property** using systematic parent-child comparison. This operation is fundamental in **data structure validation** and **heap integrity checking** where you need to **verify heap properties** are maintained after operations. The technique uses **systematic traversal** checking that each parent node is greater than or equal to its children, ensuring the complete binary tree satisfies max-heap constraints. This concept is essential in **algorithm verification**, **data structure testing**, and **system validation** where confirming heap properties ensures correct behavior of heap-based algorithms and maintains data structure invariants.

This introduces **heap property validation algorithms** and **structural verification techniques** that are crucial for **data structure integrity and efficient heap validation operations**.

**Your task:** Implement systematic parent-child validation to verify complete max-heap property compliance through efficient structural analysis.

### Examples

**Input:**
```
arr = [90, 15, 10, 7, 12, 2]
```
**Output:**
```
true
```

---

**Input:**
```
arr = [9, 15, 10, 7, 12, 2]
```
**Output:**
```
false
```

---

## 3. Merge K Sorted Arrays
A problem that teaches multi-way merging techniques and demonstrates heap-based algorithm optimization for efficient sorted sequence combination using priority queue coordination methods.

Given **k sorted arrays**, merge them into a **single sorted array** using heap-based multi-way merge algorithm. This operation is fundamental in **external sorting** and **distributed data processing** where you need to **combine multiple sorted sequences** efficiently while maintaining overall sorted order. The technique uses **min-heap coordination** to track the smallest available element from each array, ensuring optimal merging without redundant comparisons. This concept is essential in **database systems**, **distributed computing**, and **large-scale data processing** where merging sorted partitions enables efficient data consolidation and parallel processing optimization.

This teaches **multi-way merge algorithms** and **heap-based coordination techniques** that are essential for **sorted sequence combination and efficient distributed data processing operations**.

**Your task:** Implement heap-coordinated multi-way merge to efficiently combine multiple sorted arrays while maintaining optimal time complexity and sorted order.

### Examples

**Input:**
```
[[1, 3], [2, 4], [5, 6]]
```
**Output:**
```
[1, 2, 3, 4, 5, 6]
```

---

**Input:**
```
[[1, 4, 5], [1, 3, 4], [2, 6]]
```
**Output:**
```
[1, 1, 2, 3, 4, 4, 5, 6]
```
