<h2 align="center">Day 43 (29/07/2025)</h2>

## 1. Reverse First K Elements of Queue
A problem that demonstrates partial queue manipulation techniques and teaches selective element reversal using auxiliary data structures while preserving the First-In-First-Out principle for remaining elements.

Given a queue and an integer **k**, reverse the **first k elements** of the queue while maintaining the order of the **rest of the elements**. This operation challenges traditional queue behavior by requiring **selective modification** of specific positions without disrupting the overall FIFO structure. The technique is fundamental in **data stream processing** and **buffer management** where you need to **reorder specific segments** while preserving the sequence of unaffected elements. Understanding this concept is crucial for **packet processing**, **task scheduling**, and **priority queue modifications** where partial reordering optimizes processing efficiency without complete restructuring.

This teaches **selective queue manipulation algorithms** and **partial reversal techniques** that are essential for **stream processing and efficient queue segment modification operations**.

**Your task:** Use auxiliary data structures to reverse the first k queue elements while maintaining FIFO order for the remaining elements.

### Examples

**Input:**
```
Queue = [1, 2, 3, 4, 5], k = 3
```
**Output:**
```
[3, 2, 1, 4, 5]
```

---

**Input:**
```
Queue = [10, 20, 30], k = 2
```
**Output:**
```
[20, 10, 30]
```

---

## 2. Generate Binary Numbers from 1 to N using Queue
A problem that introduces systematic number generation techniques and teaches breadth-first binary construction using queue-based pattern expansion for efficient sequence generation.

Given a number **n**, generate **binary numbers from 1 to n** using a queue-based approach and return them as a list. This operation demonstrates **systematic pattern generation** where each binary number is constructed by **extending previous numbers** with '0' and '1' suffixes. The technique is fundamental in **number system conversion** and **systematic enumeration** where you need to **generate sequences efficiently** using breadth-first construction. Understanding this concept is crucial for **combinatorial generation**, **tree traversal patterns**, and **systematic search algorithms** where queue-based expansion produces ordered sequences naturally.

This introduces **systematic generation algorithms** and **breadth-first construction techniques** that are crucial for **number system processing and efficient sequence enumeration operations**.

**Your task:** Implement queue-based binary number generation by systematically expanding each number with '0' and '1' extensions using FIFO processing.

### Examples

**Input:**
```
n = 5
```
**Output:**
```
["1", "10", "11", "100", "101"]
```

---

**Input:**
```
n = 3
```
**Output:**
```
["1", "10", "11"]
```

---

## 3. Check if a Queue is Palindrome
A problem that teaches symmetry detection algorithms and demonstrates combined queue-stack operations for sequence analysis using complementary data structure properties for pattern recognition.

Given a queue of characters, determine whether the sequence forms a **palindrome** using only **queue and stack operations**. This operation requires understanding **symmetry analysis** where you need to **compare sequence elements** from both ends using the complementary properties of FIFO and LIFO structures. The technique is fundamental in **pattern recognition** and **string analysis** where you need to **detect symmetric properties** efficiently. Understanding this concept is crucial for **data validation**, **sequence verification**, and **structural analysis** where palindrome detection indicates special mathematical or linguistic properties.

This teaches **symmetry detection algorithms** and **dual data structure techniques** that are essential for **pattern recognition and efficient sequence symmetry analysis operations**.

**Your task:** Use complementary queue and stack operations to systematically compare sequence elements for palindrome detection through structural symmetry analysis.

### Examples

**Input:**
```
['r', 'a', 'c', 'e', 'c', 'a', 'r']
```
**Output:**
```
Yes
```

---

**Input:**
```
['a', 'b', 'c']
```
**Output:**
```
No
```
