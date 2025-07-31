<h2 align="center">Day 39 (24/07/2025)</h2>

## 1. Reverse a Stack using Recursion
A problem that demonstrates advanced recursive techniques and teaches in-place data structure manipulation without auxiliary storage through systematic recursive operations.

Reverse the elements of a stack without using any **extra space** (use **recursion only**). This operation challenges traditional reversal approaches by eliminating auxiliary data structures and relying purely on **recursive call stack** for temporary storage. The technique is fundamental in **space-constrained algorithms** and **in-place manipulation** where you need to **transform data structures** without additional memory allocation. Understanding this concept is crucial for **memory-efficient programming** and **recursive problem solving** where the call stack itself becomes the working storage. This approach teaches **advanced recursion patterns** that are essential for implementing complex transformations with minimal space overhead.

This teaches **in-place recursive algorithms** and **call stack utilization techniques** that are essential for **memory-efficient data structure manipulation and space-optimized recursive operations**.

**Your task:** Implement recursive stack reversal using only the implicit call stack as temporary storage while maintaining O(1) auxiliary space complexity.

### Examples

**Input:**
```
[1, 2, 3]



```
**Output:**
```
[3, 2, 1]
```

---

**Input:**
```
[5, 6]

```
**Output:**
```
[6, 5]
```

---

## 2. Stock Span Problem
A problem that introduces financial algorithm applications and teaches monotonic stack techniques for analyzing time-series data and computing backward-looking statistics efficiently.

Given a list of daily stock prices, return the **span of stocks** for each day using a stack-based approach. The span represents the number of **consecutive days before** the current day with **smaller or equal price**. This operation is fundamental in **financial analysis** and **technical indicators** where you need to **compute price momentum** and **trend analysis metrics**. The technique uses a **monotonic decreasing stack** to efficiently track previous higher prices, enabling **O(n) time complexity** for span calculation. This concept is essential in **algorithmic trading**, **market analysis**, and **time-series processing** where efficient backward-looking computations are crucial for real-time decision making.

This introduces **financial algorithm techniques** and **time-series analysis methods** that are crucial for **trading systems and efficient market data processing operations**.

**Your task:** Use a monotonic stack to efficiently compute stock price spans by tracking previous higher prices for optimal time-series analysis.

### Examples

**Input:**
```
[100, 80, 60, 70, 60, 75, 85]
```
**Output:**
```
[1, 1, 1, 2, 1, 4, 6]
```

---

**Input:**
```
[10, 20, 30]
```
**Output:**
```
[1, 2, 3]
```

---

## 3. Implement 2 Stacks in an Array
A problem that teaches space-efficient data structure design and demonstrates optimal memory utilization techniques for implementing multiple stacks within shared storage constraints.

Design a data structure that implements **two stacks** in **one array** such that neither stack overflows until the **total space is used**. This operation requires understanding **space partitioning strategies** and **dynamic boundary management** where you need to **maximize space utilization** while maintaining stack properties. The technique is crucial in **embedded systems** and **memory-constrained environments** where you need **efficient multi-stack implementations** without wasting allocated space. This concept teaches **optimal space allocation** and **collision detection** that are essential for building efficient container classes and system-level data structures.

This teaches **space-efficient container design** and **memory optimization techniques** that are essential for **system programming and resource-constrained data structure implementations**.

**Your task:** Design a dual-stack array implementation with optimal space utilization by managing dynamic boundaries and preventing premature overflow conditions.

### Examples

**Input:**
```
Push 1, 2 in stack1, Push 9, 8 in stack2
```
**Output:**
```
Stack1: [1, 2], Stack2: [8, 9]
```

---

**Input:**
```
Push 3 in stack1, Pop stack2
```
**Output:**
```
Stack1: [1, 2, 3], Stack2: [8]
```
