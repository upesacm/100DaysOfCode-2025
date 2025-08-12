<h2 align="center">Day 58 (12/08/2025)</h2>

## 1. Kth Smallest Element
A problem that demonstrates order statistics algorithms and teaches efficient selection techniques using min-heap data structures for rank-based element retrieval and statistical analysis operations.

Given an array and a number **k**, find the **kth smallest element** using min-heap approach. This operation is fundamental in **order statistics** and **rank-based analysis** where you need to **find elements by rank** efficiently without complete sorting. The technique uses **min-heap construction** followed by k-1 extractions to reach the kth smallest element, or alternatively uses a max-heap of size k for space optimization. This concept is essential in **statistical analysis**, **percentile calculations**, and **data ranking** where finding specific rank elements enables quantile analysis and performance benchmarking in large datasets.

This teaches **order statistic algorithms** and **rank-based selection techniques** that are essential for **statistical analysis and efficient element ranking operations**.

**Your task:** Implement min-heap based kth smallest selection using optimal heap operations to efficiently find rank-based elements.

### Examples

**Input:**
```
arr = [7, 10, 4, 3, 20, 15], k = 3
```
**Output:**
```
7
```

---

**Input:**
```
arr = [7, 10, 4, 20, 15], k = 4
```
**Output:**
```
15
```

---

## 2. Heapify an Array
A problem that introduces heap construction algorithms and teaches bottom-up heapification techniques using efficient in-place transformation methods for data structure conversion operations.

Convert an **unsorted array** into a **valid max-heap** using the heapify process. This operation is fundamental in **heap construction** and **data structure transformation** where you need to **establish heap properties** efficiently from arbitrary data. The technique uses **bottom-up heapification** starting from the last non-leaf node and applying sift-down operations to maintain heap invariants. This concept is essential in **heap sort implementation**, **priority queue initialization**, and **algorithm optimization** where efficient heap construction enables fast sorting and priority-based operations on unorganized data.

This introduces **heap construction algorithms** and **bottom-up heapification techniques** that are crucial for **data structure transformation and efficient heap initialization operations**.

**Your task:** Implement bottom-up heapification using sift-down operations to efficiently convert unsorted arrays into valid max-heap structures.

### Examples

**Input:**
```
arr = [3, 5, 9, 6, 8, 20, 10, 12, 18, 9]
```
**Output:**
```
A valid max-heap array
```

---

**Input:**
```
arr = [1, 3, 6, 5, 9, 8]
```
**Output:**
```
A valid max-heap array
```

---

## 3. Replace Root with New Element
A problem that teaches heap maintenance algorithms and demonstrates dynamic heap modification techniques using property restoration methods for efficient heap update operations.

Given a **max-heap**, replace the **root** with a **new value** and **maintain heap property** through appropriate restructuring operations. This operation is fundamental in **dynamic heap management** and **priority queue updates** where you need to **modify heap elements** while preserving structural invariants efficiently. The technique involves **root replacement** followed by **sift-down operations** to restore heap property by comparing with children and swapping as necessary. This concept is essential in **real-time systems**, **dynamic priority management**, and **heap-based algorithms** where maintaining heap properties during updates enables efficient priority adjustments and system responsiveness.

This teaches **heap maintenance algorithms** and **dynamic modification techniques** that are essential for **heap updates and efficient priority queue management operations**.

**Your task:** Implement root replacement with heap property restoration using sift-down operations to maintain valid heap structure after modifications.

### Examples

**Input:**
```
arr = [50, 30, 20, 15, 10, 8, 16], newElement = 25
```
**Output:**
```
New heap with root replaced and heap property maintained
```

---

**Input:**
```
arr = [100, 80, 70, 60, 50, 40, 30], newElement = 35
```
**Output:**
```
New heap with root replaced and heap property maintained
```
