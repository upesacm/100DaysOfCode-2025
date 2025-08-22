<h2 align="center">Day 51 (05/08/2025)</h2>

## 1. Longest Substring with K Unique Characters
A problem that demonstrates advanced sliding window techniques and teaches constraint-based substring optimization using dynamic window adjustment for character diversity analysis and string processing operations.

Given a string, find the length of the **longest substring** that contains **exactly k unique characters** using a sliding window approach. This operation is fundamental in **string analysis** and **pattern optimization** where you need to **find optimal segments** with specific character diversity constraints. The technique uses **variable sliding window** with character frequency tracking to maintain exactly k unique characters while maximizing substring length. This concept is essential in **text processing**, **DNA sequence analysis**, and **data compression** where finding segments with controlled character diversity enables pattern recognition and sequence optimization in biological and textual data.

This teaches **constraint-based sliding window algorithms** and **character diversity optimization techniques** that are essential for **string analysis and efficient substring pattern recognition operations**.

**Your task:** Implement dynamic sliding window with character frequency tracking to find the longest substring maintaining exactly k unique characters.

### Examples

**Input:**
```
str = "aabacbebebe", k = 3
```
**Output:**
```
7
```

---

**Input:**
```
str = "aaaa", k = 2
```
**Output:**
```
0
```

---

## 2. Smallest Subarray with Sum Greater than X
A problem that introduces minimum window optimization and teaches efficient subarray finding using sliding window techniques for threshold-based analysis and optimization problems.

Given an array and a number **x**, find the **smallest subarray** with a **sum greater than x** using sliding window technique. This operation is fundamental in **optimization analysis** and **threshold detection** where you need to **find minimal segments** that exceed specific criteria efficiently. The technique uses **variable sliding window** with dynamic expansion and contraction to minimize subarray length while maintaining sum constraints. This concept is essential in **resource optimization**, **performance analysis**, and **financial modeling** where finding minimal resource allocations that meet targets enables efficient planning and cost optimization in array-based data systems.

This introduces **minimum window algorithms** and **threshold-based optimization techniques** that are crucial for **resource analysis and efficient minimal subarray computation operations**.

**Your task:** Implement dynamic sliding window with threshold tracking to find the smallest subarray exceeding target sums through efficient window management.

### Examples

**Input:**
```
arr = [1, 4, 45, 6, 0, 19], x = 51
```
**Output:**
```
3
```

---

**Input:**
```
arr = [1, 10, 5, 2, 7], x = 9
```
**Output:**
```
1
```

---

## 3. Minimum Window Substring
A problem that teaches advanced pattern matching techniques and demonstrates complex sliding window algorithms for multi-character substring finding using frequency-based window validation methods.

Given two strings **s** and **t**, return the **minimum window** in s which **contains all characters of t** using advanced sliding window technique. This operation is fundamental in **advanced pattern matching** and **substring optimization** where you need to **find minimal containing segments** with complete character coverage. The technique uses **complex sliding window** with dual frequency tracking to maintain character requirements while minimizing window size. This concept is essential in **bioinformatics**, **text search engines**, and **data mining** where finding minimal segments containing all required elements enables efficient pattern extraction and sequence analysis in complex textual datasets.

This teaches **advanced pattern matching algorithms** and **multi-constraint window optimization techniques** that are essential for **complex substring analysis and efficient pattern containment operations**.

**Your task:** Implement advanced sliding window with dual frequency tracking to find minimal substrings containing all required characters efficiently.

### Examples

**Input:**
```
s = "ADOBECODEBANC", t = "ABC"
```
**Output:**
```
"BANC"
```

---

**Input:**
```
s = "a", t = "a"
```
**Output:**
```
"a"
```
