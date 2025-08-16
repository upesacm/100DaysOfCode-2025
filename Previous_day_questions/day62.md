<h2 align="center">Day 62 (16/08/2025)</h2>

## 1. Connect N Ropes with Minimum Cost
A problem that demonstrates greedy optimization algorithms and teaches cost minimization techniques using min-heap for optimal sequence selection in combinatorial optimization problems.

Given **N ropes** with different lengths, connect them with **minimum cost** using min-heap based greedy approach. This operation is fundamental in **combinatorial optimization** and **cost minimization** where you need to **find optimal combination sequences** that minimize total expense. The technique uses **min-heap to always combine shortest ropes** first, as connecting shorter ropes early reduces the total cost of subsequent combinations. This concept is essential in **resource optimization**, **manufacturing processes**, and **network design** where minimizing connection costs enables efficient resource utilization and optimal system design in cost-sensitive applications.

This teaches **greedy optimization algorithms** and **min-heap cost minimization techniques** that are essential for **combinatorial optimization and efficient cost reduction operations**.

**Your task:** Implement greedy rope connection using min-heap to always select shortest ropes for combination, achieving optimal cost minimization.

### Examples

**Input:**
```
[4, 3, 2, 6]
```
**Output:**
```
29
```

---

**Input:**
```
[1, 2, 3, 4, 5]
```
**Output:**
```
33
```

---

## 2. K Closest Numbers
A problem that introduces proximity-based selection and teaches distance-based heap algorithms using custom comparators for efficient nearest neighbor finding operations.

Find **k closest numbers** to a **target** using heap-based distance analysis. This operation is fundamental in **proximity analysis** and **nearest neighbor search** where you need to **identify elements closest to reference points** efficiently. The technique uses **max-heap of size k** with distance-based comparison to maintain the k closest elements, or min-heap with all distances for comprehensive analysis. This concept is essential in **machine learning**, **recommendation systems**, and **spatial analysis** where finding nearest elements enables similarity matching and clustering operations in multi-dimensional data spaces.

This introduces **proximity-based heap algorithms** and **distance optimization techniques** that are crucial for **nearest neighbor analysis and efficient similarity-based selection operations**.

**Your task:** Implement distance-based k-closest selection using heap structures with custom distance comparators for optimal proximity analysis.

### Examples

**Input:**
```
arr = [1, 2, 3, 4, 5], target = 3, k = 2
```
**Output:**
```
[2, 4]
```

---

**Input:**
```
arr = [5, 6, 7, 8, 9], target = 7, k = 3
```
**Output:**
```
[6, 7, 8]
```

---

## 3. Find Kth Largest Sum of Subarray
A problem that teaches subarray analysis optimization and demonstrates heap-based selection algorithms using sum computation and priority queue techniques for efficient ranking operations.

Given an array, find the **kth largest sum** of **contiguous subarrays** using heap-based selection approach. This operation is fundamental in **subarray analysis** and **sum-based ranking** where you need to **identify optimal segments** based on cumulative values efficiently. The technique can use **min-heap of size k** to maintain largest sums, or generate all subarray sums with max-heap for comprehensive analysis. This concept is essential in **financial analysis**, **performance monitoring**, and **optimization problems** where finding peak-performing segments enables trend identification and strategic decision making in sequence-based data analysis.

This teaches **subarray optimization algorithms** and **sum-based ranking techniques** that are essential for **segment analysis and efficient subarray performance evaluation operations**.

**Your task:** Implement subarray sum analysis using heap-based selection to efficiently identify kth largest segment sums with optimal performance.

### Examples

**Input:**
```
arr = [10, -10, 20, -40], k = 3
```
**Output:**
```
10
```

---

**Input:**
```
arr = [1, 2, 3], k = 2
```
**Output:**
```
5
```
