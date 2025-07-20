<h2 align="center">Day 36 (21/07/2025)</h2>

## 1. Reverse a String using Stack
A problem that introduces fundamental stack operations and demonstrates the Last-In-First-Out (LIFO) principle through string manipulation techniques.

You are given a string and need to use a **stack data structure** to reverse the characters and return the reversed result. This operation showcases the core **LIFO behavior** of stacks where elements are removed in the opposite order of their insertion. The challenge is fundamental in **data structure education** and teaches how stacks can be used for **order reversal operations** in various applications like **undo functionality** and **expression evaluation**. Understanding this concept is crucial for implementing **backtracking algorithms** and **parsing operations**.

This teaches **stack fundamentals** and **LIFO principles** that are essential for **algorithm design and efficient order manipulation operations**.

**Your task:** Utilize a stack's LIFO property to reverse string characters by pushing all characters and then popping them sequentially.

### Examples

**Input:**
```
"hello"
```
**Output:**
```
"olleh"
```

---

**Input:**
```
"abcde"
```
**Output:**
```
"edcba"
```

---

## 2. Check for Balanced Parentheses
A problem that demonstrates stack-based parsing techniques and teaches how to validate nested structures using systematic bracket matching algorithms.

Given a string containing parentheses **()**, **{}**, and **[]**, check whether the input string has **balanced parentheses** using a stack data structure. This operation is fundamental in **compiler design** and **expression parsing** where you need to **validate syntax correctness** and ensure proper nesting of brackets. The challenge involves understanding how stacks can track opening brackets and match them with corresponding closing brackets, making it essential for **syntax validation** and **parser implementation**. This technique is widely used in **code editors** and **mathematical expression evaluators**.

This introduces **bracket matching algorithms** and **syntax validation techniques** that are crucial for **parser development and expression evaluation systems**.

**Your task:** Use a stack to track opening brackets and validate proper pairing with closing brackets for complete balance verification.

### Examples

**Input:**
```
"([])"
```
**Output:**
```
Balanced
```

---

**Input:**
```
"(["
```
**Output:**
```
Not Balanced
```

---

## 3. Insert at Bottom of Stack
A problem that teaches advanced stack manipulation techniques and demonstrates recursive operations combined with stack-based data structure modification.

Given a stack and an element **x**, insert **x** at the **bottom of the stack** using recursion or additional stack operations without using auxiliary data structures like arrays. This operation challenges the natural **LIFO behavior** of stacks and requires **creative manipulation** to access the bottom position. The technique is important in **stack-based algorithms** where you need to **modify stack foundations** while preserving the existing order. This concept is essential for implementing **advanced stack operations** and understanding **recursive stack manipulation** in complex algorithmic scenarios.

This teaches **recursive stack operations** and **advanced stack manipulation techniques** that are essential for **complex data structure modifications and algorithmic problem solving**.

**Your task:** Insert an element at the stack's bottom position using recursive operations while maintaining the original order of existing elements.

### Examples

**Input:**
```
Stack: [1, 2, 3], x = 0
```
**Output:**
```
[0, 1, 2, 3]
```

---

**Input:**
```
Stack: [5, 6], x = 9
```
**Output:**
```
[9, 5, 6]
```
