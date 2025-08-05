<h2 align="center">Day 50 (04/08/2025)</h2>

## 1. Maximum Sum Subarray of Size K
A problem that introduces sliding window optimization techniques and teaches fixed-size subarray analysis using efficient window-based computation methods for array processing and optimization.

Given an array and a number **k**, find the **maximum sum** of a subarray of size **k** using a sliding window approach. This operation is fundamental in **array optimization** and **window-based analysis** where you need to **find optimal segments** within larger datasets efficiently. The technique uses **sliding window optimization** to avoid redundant calculations by maintaining a moving window and updating sums incrementally. This concept is essential in **signal processing**, **time series analysis**, and **performance monitoring** where finding peak values within fixed intervals enables trend analysis and anomaly detection in continuous data streams.

This teaches **sliding window algorithms** and **fixed-size optimization techniques** that are essential for **array analysis and efficient subarray computation operations**.

**Your task:** Implement sliding window technique to find the maximum sum subarray by maintaining a moving window and updating sums efficiently.

### Examples

**Input:**
```
arr = [1, 4, 2, 10], k = 2
```
**Output:**
```
12
```

---

**Input:**
```
arr = [100, 200, 300, 400], k = 2
```
**Output:**
```
700
```

---

## 2. Count Occurrences of Anagram
A problem that demonstrates pattern matching techniques and teaches anagram detection algorithms using frequency-based sliding window methods for string analysis and pattern recognition operations.

Given a **text** and a **pattern**, return the number of occurrences of the **anagram of the pattern** in the text using sliding window technique. This operation is fundamental in **string pattern matching** and **anagram analysis** where you need to **detect character rearrangements** within text efficiently. The technique uses **frequency-based sliding window** to track character counts and identify anagram matches without generating all permutations. This concept is essential in **text processing**, **plagiarism detection**, and **bioinformatics** where finding character pattern variations enables content analysis and sequence matching in large text datasets.

This introduces **anagram detection algorithms** and **frequency-based pattern matching techniques** that are crucial for **text analysis and efficient string pattern recognition operations**.

**Your task:** Implement frequency-based sliding window to detect anagram patterns by tracking character counts and identifying matching distributions.

### Examples

**Input:**
```
text = "forxxorfxdofr", pattern = "for"
```
**Output:**
```
@@ -57,42 +57,42 @@ text = "forxxorfxdofr", pattern = "for"

**Input:**
```
text = "aabaabaa", pattern = "aaba"
```
**Output:**
```
4
```

---

## 3. Subarray with Given Sum
A problem that teaches variable-size sliding window techniques and demonstrates dynamic window adjustment algorithms for target sum finding using efficient pointer-based traversal methods.

Given an array of **non-negative integers** and a **target sum**, find the subarray with the given sum using **sliding window technique**. This operation is fundamental in **subarray analysis** and **target finding** where you need to **locate specific sum ranges** within arrays efficiently. The technique uses **variable-size sliding window** with two pointers that expand and contract dynamically to match the target sum. This concept is essential in **financial analysis**, **resource allocation**, and **optimization problems** where finding segments that meet specific criteria enables decision making and resource planning in array-based data structures.

This teaches **variable sliding window algorithms** and **dynamic window adjustment techniques** that are essential for **target finding and efficient subarray sum computation operations**.

**Your task:** Implement dynamic sliding window with two pointers to find subarrays matching target sums through efficient window expansion and contraction.

### Examples

**Input:**
```
arr = [1, 4, 20, 3, 10, 5], target = 33
```
**Output:**
```
Subarray found from index 2 to 4
```

---

**Input:**
```
arr = [1, 4, 0, 0, 3, 10, 5], target = 7
```
**Output:**
```
Subarray found from index 1 to 4
```
