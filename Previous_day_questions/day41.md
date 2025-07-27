<h2 align="center">Day 41 (26/07/2025)</h2>

## 1. Remove Adjacent Duplicates from String
A problem that demonstrates string processing techniques and teaches iterative duplicate elimination using stack-based character tracking for text cleaning and optimization operations.

Given a string, remove all **adjacent duplicates** using a stack and repeat the process until **no adjacent duplicates are left**. This operation is fundamental in **text processing** and **string optimization** where you need to **eliminate redundant patterns** iteratively until a stable state is reached. The technique uses a **stack-based comparison** to detect and remove consecutive identical characters, requiring **multiple passes** until no further reductions are possible. Understanding this concept is crucial for **data compression**, **text normalization**, and **string simplification** algorithms where removing redundant sequences improves storage efficiency and processing performance.

This teaches **iterative string reduction algorithms** and **stack-based pattern elimination techniques** that are essential for **text processing and efficient string optimization operations**.

**Your task:** Use a stack to systematically remove adjacent duplicate characters through iterative elimination until achieving a stable reduced string.

### Examples

**Input:**
```
"abbaca"
```
**Output:**
```
"ca"
```

---

**Input:**
```
"azxxzy"
```
**Output:**
```
"ay"
```

---

## 2. Decode a String
A problem that introduces nested structure parsing and teaches stack-based decoding algorithms for handling recursive string expansion with numerical multipliers and bracket notation.

Given an encoded string like **"3[a]2[bc]"**, decode it using a stack where the pattern **k[substring]** means the substring inside brackets is **repeated k times**. This operation is fundamental in **data decompression** and **template expansion** where you need to **process nested repetition patterns** with variable multipliers. The technique uses **dual stack management** to track both numerical multipliers and string fragments, enabling **recursive expansion** of nested patterns. This concept is essential in **configuration parsing**, **template engines**, and **markup processing** where structured text expansion requires systematic bracket matching and content multiplication.

This introduces **nested parsing algorithms** and **recursive string expansion techniques** that are crucial for **template processing and structured text decoding operations**.

**Your task:** Implement dual-stack parsing to handle nested bracket structures with numerical multipliers for accurate recursive string expansion.

### Examples

**Input:**
```
"3[a]2[bc]"
```
**Output:**
```
"aaabcbc"
```

---

**Input:**
```
"2[abc]3[cd]ef"
```
**Output:**
```
"abcabccdcdcdef"
```

---

## 3. Remove K Digits to Make the Smallest Number
A problem that teaches greedy optimization techniques and demonstrates monotonic stack algorithms for numerical minimization while preserving digit order constraints in mathematical optimization.

You are given a string **num** representing a non-negative integer and an integer **k**. Remove exactly **k digits** from the number so that the new number is the **smallest possible** using a stack-based greedy approach. The technique maintains **relative digit order** while selecting optimal removals through **monotonic stack operations**. This operation is fundamental in **numerical optimization** and **greedy algorithms** where you need to **minimize values** under removal constraints. Understanding this concept is crucial for **competitive programming**, **algorithmic optimization**, and **mathematical problem solving** where greedy digit selection produces optimal results efficiently.

This teaches **greedy digit selection algorithms** and **monotonic optimization techniques** that are essential for **numerical minimization and efficient mathematical optimization operations**.

**Your task:** Use a monotonic stack with greedy selection to remove k digits while building the lexicographically smallest possible number.

### Examples

**Input:**
```
num = "1432219", k = 3
```
**Output:**
```
"1219"
```

---

**Input:**
```
num = "10200", k = 1
```
**Output:**
```
"200"
```
