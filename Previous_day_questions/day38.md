<h2 align="center">Day 38 (23/07/2025)</h2>

## 1. Next Greater Element
A problem that demonstrates monotonic stack techniques and teaches efficient nearest greater element finding algorithms for array processing and optimization problems.

For each element in the array, find the **next greater element** to the right using a stack-based approach. If there is no greater element, assign **-1**. This operation is fundamental in **algorithmic optimization** and **array processing** where you need to **identify nearest greater values** efficiently. The technique uses a **monotonic stack** to maintain elements in decreasing order, enabling **O(n) time complexity** instead of the naive O(n²) approach. This concept is essential in **stock span problems**, **histogram analysis**, and **competitive programming** where efficient nearest element queries are crucial for performance optimization.

This teaches **monotonic stack algorithms** and **nearest greater element techniques** that are essential for **array optimization and efficient element comparison operations**.

**Your task:** Implement a monotonic stack solution to find the next greater element for each array position in linear time complexity.

### Examples

**Input:**
```
[4, 5, 2, 25]
```
**Output:**
```
[5, 25, 25, -1]
```

---

**Input:**
```
[13, 7, 6, 12]
```
**Output:**
```
[-1, 12, 12, -1]
```

---

## 2. Min Stack
A problem that introduces auxiliary data structure design and teaches how to maintain additional information while preserving constant-time operations for specialized stack requirements.

Design a stack that supports **push**, **pop**, **top**, and retrieving the **minimum element** in **constant time O(1)**. This operation requires understanding **auxiliary storage techniques** and **invariant maintenance** where you need to **track additional metadata** without compromising basic stack operations. The challenge is crucial in **system design** and **data structure optimization** where you need **efficient minimum queries** alongside standard stack functionality. This concept teaches **space-time tradeoffs** and **auxiliary structure design** that are essential for building efficient specialized data structures.

This introduces **auxiliary data structure design** and **constant-time optimization techniques** that are crucial for **specialized container implementations and system performance optimization**.

**Your task:** Design a stack with auxiliary storage to maintain minimum element information while ensuring all operations remain O(1) complexity.

### Examples

**Input:**
```
Push: 5, 3, 7 → Get Min
```
**Output:**
```
3
```

---

**Input:**
```
Push: 8, 2, 6 → Pop → Get Min
```
**Output:**
```
2
```

---

## 3. Redundant Brackets
A problem that teaches expression analysis techniques and demonstrates stack-based parsing for identifying unnecessary parentheses in mathematical expressions through systematic bracket evaluation.

Given a valid mathematical expression in the form of a string, find whether it contains any **redundant brackets** using a stack-based approach. This operation is fundamental in **expression optimization** and **compiler design** where you need to **identify unnecessary parentheses** that don't affect operator precedence or evaluation order. The technique involves **systematic bracket tracking** and **operator counting** to determine if brackets enclose meaningful sub-expressions. This concept is essential in **code optimization**, **expression simplification**, and **parser development** where removing redundant elements improves performance and readability.

This teaches **expression parsing algorithms** and **bracket redundancy detection techniques** that are essential for **compiler optimization and mathematical expression analysis systems**.

**Your task:** Use stack-based parsing to identify redundant bracket pairs by tracking operators and operands within parentheses for optimization detection.

### Examples

**Input:**
```
"((a+b))"
```
**Output:**
```
Yes
```

---

**Input:**
```
"(a+b)"
```
**Output:**
```
No
```
