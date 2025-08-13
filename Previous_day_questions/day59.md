<h2 align="center">Day 59 (13/08/2025)</h2>

## 1. Min Heap Implementation
A problem that introduces fundamental heap data structure implementation and teaches core heap operations using array-based representation for efficient priority queue functionality and dynamic data management.

Implement basic operations (**insert**, **extractMin**) of a **min-heap** using array-based representation with proper heap property maintenance. This operation is fundamental in **data structure implementation** and **priority queue design** where you need to **maintain minimum element accessibility** while supporting dynamic insertions and deletions efficiently. The technique uses **bubble-up and bubble-down operations** to maintain heap invariants after modifications, ensuring O(log n) complexity for both operations. This concept is essential in **algorithm implementation**, **system programming**, and **priority-based scheduling** where building efficient heap structures enables optimal priority queue functionality and resource management.

This teaches **heap implementation algorithms** and **priority queue construction techniques** that are essential for **data structure design and efficient heap operation implementation**.

**Your task:** Implement complete min-heap with insert and extractMin operations using array representation and proper heap property maintenance algorithms.

### Examples

**Input:**
```
Insert 3, 2, 15 → extractMin
```
**Output:**
```
2
```

---

**Input:**
```
Insert 10, 5, 20, 8 → extractMin → extractMin
```
**Output:**
```
5, 8
```

---

## 2. Max Heap Using Priority Queue
A problem that demonstrates priority queue utilization and teaches max-heap operations using built-in data structures for efficient maximum element management and priority-based processing operations.

Insert elements into a **max heap** using **priority queue** implementation and retrieve maximum elements efficiently. This operation is fundamental in **priority-based processing** and **maximum tracking** where you need to **maintain largest element accessibility** using standard library implementations. The technique leverages **built-in priority queue structures** with appropriate comparators or value negation to achieve max-heap behavior. This concept is essential in **competitive programming**, **algorithm optimization**, and **system design** where utilizing standard priority queue implementations enables rapid development and reliable maximum element management.

This introduces **priority queue utilization algorithms** and **max-heap management techniques** that are crucial for **efficient maximum tracking and priority-based element processing operations**.

**Your task:** Implement max-heap functionality using priority queue libraries with proper element insertion and maximum extraction operations.

### Examples

**Input:**
```
Insert 5, 1, 10 → extractMax
```
**Output:**
```
10
```

---

**Input:**
```
Insert 3, 7, 2, 9 → extractMax → extractMax
```
**Output:**
```
9, 7
```

---

## 3. Check if Two Heaps are Identical
A problem that teaches heap structure comparison and demonstrates array-based heap equality verification using systematic element and structural analysis for heap validation operations.

Given **two arrays**, check if they **represent the same heap structure** through comprehensive structural and element comparison. This operation is fundamental in **heap validation** and **data structure verification** where you need to **confirm heap equivalence** beyond simple element equality. The technique involves **systematic array comparison** ensuring both element values and heap property satisfaction are identical across both structures. This concept is essential in **testing frameworks**, **algorithm verification**, and **data structure validation** where confirming heap equality ensures correctness of heap operations and maintains data structure integrity in complex systems.

This teaches **heap comparison algorithms** and **structural verification techniques** that are essential for **heap validation and efficient data structure equality checking operations**.

**Your task:** Implement comprehensive heap equality checking using array comparison with heap property verification for complete structural validation.

### Examples

**Input:**
```
arr1 = [10, 9, 8], arr2 = [10, 9, 8]
```
**Output:**
```
true
```

---

**Input:**
```
arr1 = [10, 9, 8], arr2 = [10, 8, 9]
```
**Output:**
```
false
```
