
<h2 align="center">Day 32 (17/07/2025)</h2>

## 1. Swap Two Numbers Without Temporary Variable  
A classic bitwise trick that shows how XOR can be used to **swap values without using extra memory**. This problem reinforces the concept that XOR has properties which make it suitable for in-place data manipulation.

Given two integers **a** and **b**, swap their values using **bitwise XOR** without using any temporary variable. This is a common interview question to test your understanding of bitwise fundamentals.

This teaches **XOR logic**, **in-place data manipulation**, and **memory-efficient algorithms**, useful for **embedded systems** and **interview prep**.

**Your task:** Swap two integers using only bitwise operators.

### Examples

**Input:**
```
a = 4, b = 7
```
**Output:**
```
a = 7, b = 4
```

---

**Input:**
```
a = 1, b = 2
```
**Output:**
```
a = 2, b = 1
```

---

## 2. Find the Only Non-Repeating Element  
A problem that leverages XOR's property where identical bits cancel out, helping you find a **unique element** in a set of duplicates.

Given an array of integers where every element appears twice **except for one**, find the unique **non-repeating element** using bitwise XOR. This is efficient and requires no additional memory, unlike frequency maps.

This teaches **XOR aggregation**, **data deduplication**, and **memory-optimized searching**, which are highly valuable for **competitive programming** and **low-memory devices**.

**Your task:** Find the single non-repeating number using XOR.

### Examples

**Input:**
```
arr = [2, 3, 2]
```
**Output:**
```
3
```

---

**Input:**
```
arr = [5, 1, 1, 5, 7]
```
**Output:**
```
7
```

---

## 3. Find XOR of All Numbers in an Array  
An introductory problem in **bitwise accumulation** that builds a strong foundation for many XOR-based problems.

Write a function to **compute the XOR of all elements** in the array. XOR acts like a parity check, and this concept is frequently used in **encryption**, **checksum validation**, and **binary data processing**.

This teaches **bitwise reduction techniques**, **XOR properties**, and is a stepping stone toward **advanced XOR-based algorithms**.

**Your task:** Return the result of XORing all numbers in the array.

### Examples

**Input:**
```
arr = [1, 2, 3]
```
**Output:**
```
0
```

---

**Input:**
```
arr = [4, 5, 6]
```
**Output:**
```
7
```

---
