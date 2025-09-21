<h2 align="center">Day 99 (22/09/2025)</h2>

## 1. Array Sum with String Analysis 
A problem that combines fundamental array operations with string manipulation, testing basic skills from the foundational weeks.

Given an array of integers and a string, write a program that:
1. Calculates the **sum of all positive numbers** in the array
2. Counts the **number of vowels** (a, e, i, o, u) in the string (case-insensitive)
3. Returns both results

This problem tests your understanding of **array traversal**, **conditional logic**, and **string character analysis** from the fundamentals covered in Weeks 1-2.

**Your task:** Process the array and string to return the sum of positive numbers and vowel count.

### Examples

**Input:**
```
arr = [1, -2, 3, -4, 5], string = "Hello World"
```
**Output:**
```
Sum: 9, Vowels: 3
```

---

**Input:**
```
arr = [-1, -2, -3], string = "Programming"
```
**Output:**
```
Sum: 0, Vowels: 3
```

---

## 2. Stack-based Maximum Window 
A problem that combines stack operations with sliding window technique, integrating concepts from intermediate data structures.

Given an array of integers and a window size **k**, use a **stack-based approach** to find the **maximum element in each sliding window** of size k. Unlike typical sliding window solutions, implement this using stack operations to manage the window elements.

This problem integrates **stack manipulation** from Week 6 with **sliding window optimization** from Week 8, requiring you to think creatively about data structure usage.

**Your task:** Use stack operations to track and find maximum elements in each sliding window of size k.

### Examples

**Input:**
```
arr = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
```
**Output:**
```
[3, 3, 5, 5, 6, 7]
```

---

**Input:**
```
arr = [4, 2, 1, 5], k = 2
```
**Output:**
```
[4, 2, 5]
```

---

## 3. Tree Path Dynamic Programming 
A complex problem that combines binary tree traversal, path finding, and dynamic programming optimization techniques.

Given a **binary tree** where each node contains an integer value, find the **maximum sum path** from any node to any other node in the tree using dynamic programming principles. The path can start and end at any nodes and must follow parent-child connections.

This advanced problem combines **tree traversal** from Week 11, **optimization thinking** from greedy algorithms (Week 10), and **dynamic programming** from Week 14, requiring sophisticated algorithmic thinking.

**Your task:** Implement a solution that finds the maximum sum path between any two nodes in the binary tree.

### Examples

**Input:**
```
Tree:
    10
   /  \
  2    10
 / \     \
20  1    -25
          / \
         3   4
```
**Output:**
```
42 (path: 20 → 2 → 10 → 10)
```

---

**Input:**
```
Tree:
  -10
  /  \
 9   20
    /  \
   15   7
```
**Output:**
```
42 (path: 15 → 20 → 7)
```
