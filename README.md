<h2 align="center">Day 37 (22/07/2025)</h2>

## 1. Sort a Stack using Another Stack
A problem that demonstrates advanced stack manipulation techniques and teaches efficient sorting algorithms using only stack-based operations without auxiliary data structures.

Given a stack of integers, sort it in **ascending order** using only **another stack** as auxiliary storage (no arrays, lists, or other data structures allowed). This operation challenges traditional sorting approaches and requires understanding **stack-based sorting algorithms** that work within the constraints of LIFO operations. The technique is crucial in **memory-constrained environments** where you need to **sort data efficiently** using minimal additional space. This approach teaches how to leverage **temporary stack storage** for organizing data while maintaining the fundamental properties of stack operations throughout the sorting process.

This teaches **constrained sorting algorithms** and **stack-based data organization techniques** that are essential for **memory-efficient sorting and space-optimized algorithmic solutions**.

**Your task:** Implement a sorting algorithm using only stack operations and one additional stack as temporary storage for efficient data organization.

### Examples

**Input:**
```
[3, 1, 4, 2]
```
**Output:**
```
[1, 2, 3, 4]
```

---

**Input:**
```
[6, 5, 8]
```
**Output:**
```
[5, 6, 8]
```

---

## 2. Evaluate Postfix Expression
A problem that introduces stack-based expression evaluation and teaches how to process Reverse Polish Notation using systematic operand and operator handling techniques.

Given a **postfix expression** (Reverse Polish Notation), evaluate the mathematical result using a stack data structure. This operation is fundamental in **compiler design** and **expression parsing** where postfix notation eliminates the need for parentheses and operator precedence rules. The technique is essential in **calculator implementations** and **mathematical expression evaluators** where you need to **process operators systematically** after encountering their operands. Understanding postfix evaluation is crucial for **stack-based virtual machines** and **expression compilation** in programming language interpreters.

This introduces **postfix evaluation algorithms** and **expression processing techniques** that are crucial for **compiler development and mathematical computation systems**.

**Your task:** Use a stack to systematically process operands and operators in postfix notation for accurate mathematical expression evaluation.

### Examples

**Input:**
```
"231*+9-"
```
**Output:**
```
-4
```

---

**Input:**
```
"52+"
```
**Output:**
```
7
```

---

## 3. Delete Middle Element of Stack
A problem that teaches precision stack manipulation and demonstrates recursive techniques for accessing and modifying specific stack positions using positional algorithms.

Given a stack, delete its **middle element** using only **stack operations** and **recursion** without converting to other data structures. This operation requires understanding **positional calculations** in stacks and implementing **recursive traversal** to reach specific elements while preserving the order of remaining elements. The technique is important in **data structure maintenance** where you need to **remove specific elements** from constrained access structures. This concept teaches **recursive stack traversal** and **selective element removal** techniques that are essential for advanced stack-based algorithms and data manipulation operations.

This teaches **recursive stack traversal** and **positional element manipulation techniques** that are essential for **advanced data structure operations and selective element processing**.

**Your task:** Implement recursive stack operations to locate and remove the middle element while maintaining the original order of all other elements.

### Examples

**Input:**
```
[1, 2, 3, 4, 5]
```
**Output:**
```
[1, 2, 4, 5]
```

---

**Input:**
```
[10, 20, 30]
```
**Output:**
```
[10, 30]
```
