<h2 align="center">Day 33 (18/07/2025)</h2>

## 1. Check if Two Numbers Have Opposite Signs  
A fundamental bitwise check that determines if two integers have **opposite signs** by using the sign bit. This is commonly used in systems programming, signal handling, and even game logic.

Given two integers **a** and **b**, use bitwise operations to check if they have opposite signs. This works because the sign bit (most significant bit) will differ if the signs are different.

This teaches **sign bit manipulation**, **XOR/sign checking**, and is useful in **low-level debugging** or **optimization**.

**Your task:** Check whether two numbers have opposite signs using bitwise operations.

### Examples

**Input:**
```
a = 2, b = -3
```
**Output:**
```
True
```

---

**Input:**
```
a = -4, b = -5
```
**Output:**
```
False
```

---

## 2. Turn Off the Rightmost Set Bit  
A popular bit manipulation technique that clears the **rightmost set bit (1)** from a number. This is often used in **bit counting algorithms** or **efficient looping**.

Given an integer **n**, use bitwise operations to turn off its rightmost 1-bit.

This teaches **AND with (n - 1)**, a classic trick used in **Hamming weight**, **submask enumeration**, and **power-of-two logic**.

**Your task:** Clear the rightmost set bit of the number.

### Examples

**Input:**
```
n = 12
```
**Output:**
```
8
```

---

**Input:**
```
n = 10
```
**Output:**
```
8
```

---

## 3. Isolate the Rightmost Set Bit  
This problem helps you extract the **rightmost 1-bit** from a number while resetting all other bits — a useful technique in many **binary search optimizations**, **bit masks**, and **hardware manipulation routines**.

Given an integer **n**, isolate and return only the rightmost set bit as a new number (all other bits should be 0).

This teaches **bit masking**, **two’s complement logic**, and **bitfield extraction**.

**Your task:** Isolate the rightmost set bit of the number.

### Examples

**Input:**
```
n = 10
```
**Output:**
```
2
```

---

**Input:**
```
n = 12
```
**Output:**
```
4
```
