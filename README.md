<h2 align="center">Day 69 (23/08/2025)</h2>

## 1. Rearrange Array to Form Palindrome
A problem that demonstrates character frequency analysis and teaches palindrome feasibility algorithms using counting-based validation for efficient string arrangement and symmetry verification operations.

Given a **string**, check if characters can be **rearranged to form a palindrome** using frequency-based feasibility analysis approach. This operation is fundamental in **palindrome validation** and **arrangement checking** where you need to **determine structural possibility** without actual rearrangement efficiently. The technique uses **character frequency counting** to verify palindrome constraints: at most one character can have odd frequency (for middle position), while all others must have even frequencies for symmetric placement. This concept is essential in **string validation**, **data integrity checking**, and **structural analysis** where determining feasibility before processing enables efficient validation and optimal decision making in arrangement-based applications.

This demonstrates **frequency analysis algorithms** and **palindrome validation techniques** that are crucial for **string feasibility checking and efficient arrangement verification operations**.

**Your task:** Implement character frequency analysis using counting-based validation to determine palindrome rearrangement feasibility without actual string manipulation.

### Examples

**Input:**
```
"civic"
```
**Output:**
```
Yes
```

---

**Input:**
```
"aabbcc"
```
**Output:**
```
Yes
```

---

**Input:**
```
"abc"
```
**Output:**
```
No
```

---

## 2. Split Array into Equal Sum
A problem that introduces partition feasibility analysis and teaches subset sum validation algorithms using mathematical approach for efficient array division and balance verification operations.

Given an **array**, check if it can be **divided into two parts** with **equal sum** using subset sum feasibility validation strategy. This operation is fundamental in **partition analysis** and **balance checking** where you need to **determine equal distribution possibility** for optimal resource allocation efficiently. The technique uses **total sum analysis** first to check if sum is even (necessary condition), then applies subset sum algorithms to verify if a subset with target sum (total/2) exists. This concept is essential in **load balancing**, **resource distribution**, and **team formation** where ensuring equal partitions enables fair allocation and optimal system balance in distribution-based scenarios.

This introduces **partition analysis algorithms** and **subset sum validation techniques** that are essential for **array division checking and efficient balance verification operations**.

**Your task:** Implement partition feasibility analysis using subset sum validation to determine equal-sum division possibility with optimal mathematical verification.

### Examples

**Input:**
```
arr = [1, 2, 3, 5]
```
**Output:**
```
false
```

---

**Input:**
```
arr = [1, 5, 11, 5]
```
**Output:**
```
true
```

---

## 3. Longest Substring Without Repeating
A problem that teaches sliding window optimization and demonstrates character uniqueness algorithms using two-pointer technique for efficient substring analysis and length maximization operations.

Given a **string**, find the **length of longest substring** without **repeating characters** using sliding window optimization approach. This operation is fundamental in **substring analysis** and **uniqueness validation** where you need to **maximize unique character sequences** while maintaining efficiency. The technique uses **sliding window with hash set** to expand the window when characters are unique and contract from left when duplicates are found, maintaining the longest valid substring length. This concept is essential in **text processing**, **pattern analysis**, and **data streaming** where finding optimal unique sequences enables efficient parsing and maximum utilization in character-based processing systems.

This teaches **sliding window algorithms** and **substring optimization techniques** that are crucial for **text analysis and efficient uniqueness validation operations**.

**Your task:** Implement sliding window optimization using two-pointer technique with character tracking to find maximum length substring without character repetition.

### Examples

**Input:**
```
"abcabcbb"
```
**Output:**
```
3
```

---

**Input:**
```
"bbbbb"
```
**Output:**
```
1
```
