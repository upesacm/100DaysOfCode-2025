<h2 align="center">Day 29 (14/07/2025)</h2>

## 1. Check if a Number is Even or Odd Using Bit Manipulation
A problem that introduces the basics of bitwise operations and how they can be used for simple arithmetic checks.

You are given an integer *n*. Using bitwise operations, determine if the number is even or odd. Do **not** use the modulus operator. This operation is fundamental in low-level programming and embedded systems, where direct bit manipulation is often preferred for efficiency.

This teaches the use of *bitwise AND* to check the least significant bit, a common technique for quickly determining number parity.

*Your task:* Check whether a number is even or odd using only bitwise operations.

### Examples

*Input:*

4

*Output:*

Even

---

*Input:*

7

*Output:*

Odd

---

## 2. Get the i-th Bit of a Number
A problem that demonstrates how to extract specific bits from an integer using bitwise operations.

Given an integer *n* and a position *i* (0-indexed from the right), find whether the *i-th bit* is set (1) or not (0) using bitwise operations. This operation is widely used in *flag checking* and *feature toggling* at the binary level.

This teaches *bit masking* and how to test individual bits using bitwise AND and shift operations.

*Your task:* Find and return the value of the i-th bit (0 or 1) for a given number.

### Examples

*Input:*

n = 5, i = 0

*Output:*

1

---

*Input:*

n = 5, i = 1

*Output:*

0

---

## 3. Set the i-th Bit of a Number
A problem that teaches how to manipulate specific bits to enable features or flags using bitwise operations.

You are given an integer *n* and a position *i*. Set the *i-th bit* (0-indexed from right) of the number to 1 using bitwise operations and return the new number. This is commonly used in *configuration management* and *feature enabling* scenarios.

This teaches *bit setting* techniques using bitwise OR and shift operations.

*Your task:* Set a specific bit to 1 in an integer using bitwise operations.

### Examples

*Input:*

n = 5, i = 1

*Output:*

7

---

*Input:*

n = 8, i = 2

*Output:*

12

---
