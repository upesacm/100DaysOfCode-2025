<h2 align="center">Day 40 (25/07/2025)</h2>

## 1. Celebrity Problem
A problem that demonstrates graph theory applications and teaches efficient candidate elimination techniques using stack-based algorithms for social network analysis and relationship mapping.

In a party of **n people**, find the **celebrity** using a stack-based approach. A celebrity is **known by everyone** but **knows no one**. This operation is fundamental in **graph theory** and **social network analysis** where you need to **identify central nodes** with specific connectivity properties. The technique uses **systematic elimination** through stack operations to reduce the search space from O(n²) to **O(n) time complexity**. Understanding this concept is crucial for **influence analysis**, **network topology** problems, and **graph traversal optimization** where identifying nodes with unique properties requires efficient filtering algorithms.

This teaches **graph-based elimination algorithms** and **social network analysis techniques** that are essential for **relationship mapping and efficient node identification in complex network structures**.

**Your task:** Use stack-based candidate elimination to efficiently identify the celebrity by systematically reducing potential candidates through relationship queries.

### Examples

**Input:**
```
Matrix for 3 people
0 1 1
0 0 1
0 0 0
```
**Output:**
```
2
```

---

**Input:**
```
0 1
1 0
```
**Output:**
```
-1
```

---

## 2. Largest Rectangle in Histogram
A problem that introduces computational geometry applications and teaches advanced monotonic stack techniques for area optimization and geometric analysis in histogram data structures.

Given **n non-negative integers** representing histogram bar heights, find the area of the **largest rectangle** that can be formed using a stack-based approach. This operation is fundamental in **computational geometry** and **area optimization** where you need to **find maximum rectangular regions** within constrained boundaries. The technique uses a **monotonic increasing stack** to efficiently track potential rectangle boundaries, enabling **O(n) time complexity** for area computation. This concept is essential in **image processing**, **architectural design**, and **optimization problems** where maximum area calculations are crucial for space utilization and geometric analysis.

This introduces **computational geometry algorithms** and **area optimization techniques** that are crucial for **geometric analysis and efficient spatial computation operations**.

**Your task:** Implement a monotonic stack solution to find the maximum rectangular area by tracking height boundaries and computing optimal width extensions.

### Examples

**Input:**
```
[2,1,5,6,2,3]
```
**Output:**
```
10
```

---

**Input:**
```
[2,4]
```
**Output:**
```
4
```

---

## 3. Design a Stack that Supports getMax()
A problem that teaches specialized container design and demonstrates auxiliary data structure techniques for maintaining maximum element tracking with constant-time query operations.

Implement a stack that supports **push**, **pop**, and also retrieving the **maximum element** in **constant time O(1)**. This operation requires understanding **auxiliary storage optimization** and **maximum tracking algorithms** where you need to **maintain metadata efficiently** alongside standard stack operations. The technique involves **parallel data structure management** to track maximum values without compromising performance. This concept is crucial in **system design**, **database indexing**, and **real-time analytics** where efficient maximum queries are essential for performance monitoring and statistical analysis operations.

This teaches **auxiliary metadata management** and **constant-time optimization techniques** that are essential for **specialized container implementations and high-performance data structure design**.

**Your task:** Design a stack with auxiliary maximum tracking to maintain peak element information while ensuring all operations remain O(1) complexity.

### Examples

**Input:**
```
Push: 3, 5, 2 → getMax
```
**Output:**
```
5
```

---

**Input:**
```
Pop → getMax
```
**Output:**
```
3
```
