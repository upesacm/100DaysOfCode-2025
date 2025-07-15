<h2 align="center">Day 30 (15/07/2025)</h2>

## 1. Clear the i-th Bit of a Number
A problem that introduces bit clearing techniques and teaches how to unset specific bit positions using bitwise operations for selective bit manipulation.

Given a number *n* and a bit position *i, clear the **i-th bit* of the number (i.e., set it to 0) and return the new number using bitwise operations. This operation is fundamental in *system programming* and *configuration management* where you need to *disable specific flags* or *reset particular bits* without affecting other positions. The challenge involves understanding how to create appropriate masks and use bitwise operations to selectively clear bits while preserving the rest of the number.

This teaches *bit clearing* and *selective bit reset* techniques that are essential for *flag management and efficient bit-level configuration operations*.

*Your task:* Clear a specific bit position to 0 using bitwise operations while preserving all other bits.

### Examples

*Input:*

n = 7, i = 1

*Output:*

5


---

*Input:*

n = 10, i = 3

*Output:*

2


---

## 2. Toggle the i-th Bit of a Number
A problem that demonstrates bit toggling techniques and teaches how to flip specific bit positions using bitwise operations for dynamic bit manipulation.

Given a number *n* and an index *i, toggle the **i-th bit* (if 0 set to 1, if 1 set to 0) using bit manipulation and return the updated value. This operation is commonly used in *state management* and *toggle switches* where you need to *flip the state of specific bits* dynamically. The challenge involves understanding how to use XOR operations effectively to toggle bits without knowing their current state, making it useful for implementing switches and state toggles.

This introduces *bit toggling* and *XOR-based bit manipulation* techniques that are crucial for *state management and dynamic bit switching operations*.

*Your task:* Toggle a specific bit position using XOR operations to flip its current state efficiently.

### Examples

*Input:*

n = 10, i = 1

*Output:*

8


---

*Input:*

n = 5, i = 2

*Output:*

1


---

## 3. Count Set Bits in an Integer
A problem that teaches bit counting techniques and demonstrates how to analyze binary representations using efficient bit manipulation algorithms.

Write a program to count the number of *bits set to 1* in the binary representation of a given integer *n* using bit manipulation. This operation is fundamental in *computer science* and *digital signal processing* where you need to *analyze binary patterns* or *calculate Hamming weights. You can solve this using simple iteration, but try to think of **more efficient approaches* using techniques like Brian Kernighan's algorithm or built-in population count functions.

This teaches *bit counting algorithms* and *binary analysis techniques* that are essential for *digital signal processing and efficient binary data analysis*.

*Your task:* Count the number of set bits in an integer using efficient bit manipulation techniques beyond simple iteration.

### Examples

*Input:*

n = 7

*Output:*

3


---

*Input:*

n = 9

*Output:*

2
