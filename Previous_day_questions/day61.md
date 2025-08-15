<h2 align="center">Day 61 (15/08/2025)</h2>

## 1. Convert Min Heap to Max Heap
A problem that demonstrates heap transformation algorithms and teaches property conversion techniques using bottom-up heapification methods for efficient data structure type modification operations.

Given a **min heap**, convert it into a **max heap** using efficient transformation algorithms. This operation is fundamental in **heap property conversion** and **data structure adaptation** where you need to **change heap semantics** without rebuilding from scratch. The technique uses **bottom-up heapification** with reversed comparison logic, starting from non-leaf nodes and applying sift-down operations with max-heap properties. This concept is essential in **algorithm adaptation**, **data structure reuse**, and **system optimization** where converting existing heap structures enables functionality changes without complete reconstruction, saving computational resources and maintaining existing data.

This teaches **heap transformation algorithms** and **property conversion techniques** that are essential for **data structure adaptation and efficient heap type modification operations**.

**Your task:** Implement bottom-up max-heapification on existing min-heap structure to efficiently convert heap properties while preserving all elements.

### Examples

**Input:**
```
arr = [1, 3, 5, 7, 9, 2]
```
**Output:**
```
A valid max heap array
```

---

**Input:**
```
arr = [2, 4, 6, 8, 10, 12]
```
**Output:**
```
A valid max heap array
```

---

## 2. Insert and Delete in Heap
A problem that introduces comprehensive heap manipulation and teaches dynamic heap operations using insertion and deletion algorithms for complete heap management functionality.

Perform **insert and delete operations** in a **max heap** using proper heap maintenance algorithms. This operation is fundamental in **dynamic heap management** and **priority queue operations** where you need to **modify heap contents** while preserving structural properties efficiently. The technique combines **bubble-up insertion** for new elements and **extract-root deletion** with heap property restoration through sift-down operations. This concept is essential in **priority scheduling**, **event management**, and **resource allocation** where dynamic heap modifications enable real-time priority adjustments and efficient resource management in changing system conditions.

This introduces **comprehensive heap manipulation algorithms** and **dynamic operation techniques** that are crucial for **priority queue management and efficient heap modification operations**.

**Your task:** Implement complete heap manipulation with proper insertion using bubble-up and deletion using extract-root with sift-down restoration.

### Examples

**Input:**
```
Insert 20, 15, 8 → Delete root
```
**Output:**
```
Heap after operations
```

---

**Input:**
```
Insert 30, 25, 10, 35 → Delete root → Insert 40
```
**Output:**
```
Heap after operations
```

---

## 3. Heap Sort
A problem that teaches comparison-based sorting optimization and demonstrates heap-based sorting algorithms using heapification and systematic extraction for efficient in-place sorting operations.

Sort an array using **heap sort algorithm** through heapification and systematic maximum extraction. This operation is fundamental in **comparison-based sorting** and **in-place algorithm design** where you need to **achieve O(n log n) performance** with guaranteed worst-case complexity and minimal space overhead. The technique uses **initial heapification** followed by **iterative root extraction** with heap size reduction, placing sorted elements at array end. This concept is essential in **system programming**, **embedded systems**, and **performance-critical applications** where guaranteed sorting performance with minimal memory usage enables reliable sorting in resource-constrained environments.

This teaches **heap-based sorting algorithms** and **in-place optimization techniques** that are essential for **guaranteed performance sorting and efficient comparison-based array ordering operations**.

**Your task:** Implement complete heap sort using initial heapification followed by systematic extraction with in-place element positioning for optimal sorting.

### Examples

**Input:**
```
arr = [4, 10, 3, 5, 1]
```
**Output:**
```
[1, 3, 4, 5, 10]
```

---

**Input:**
```
arr = [12, 11, 13, 5, 6, 7]
```
**Output:**
```
[5, 6, 7, 11, 12, 13]
```
