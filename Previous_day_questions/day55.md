<h2 align="center">Day 55 (09/08/2025)</h2>

## 1. Longest Subarray with Sum K
A problem that demonstrates prefix sum optimization and teaches hash-based subarray finding algorithms using cumulative sum techniques for efficient target sum detection and length maximization operations.

Given an array and integer **k**, find the length of the **longest subarray** with **sum equal to k** using prefix sum and hash map approach. This operation is fundamental in **subarray optimization** and **target sum analysis** where you need to **find maximum length segments** meeting specific sum criteria efficiently. The technique uses **prefix sum tracking** with hash-based storage to detect when cumulative sums differ by exactly k, enabling O(n) time complexity. This concept is essential in **financial analysis**, **performance tracking**, and **data segmentation** where finding longest periods meeting target metrics enables trend analysis and performance optimization.

This teaches **prefix sum algorithms** and **hash-based subarray optimization techniques** that are essential for **target sum analysis and efficient length maximization operations**.

**Your task:** Implement prefix sum tracking with hash map storage to efficiently find longest subarrays meeting exact sum requirements.

### Examples

**Input:**
```
arr = [10, 5, 2, 7, 1, 9], k = 15
```
**Output:**
```
4
```

---

**Input:**
```
arr = [1, 2, 3], k = 3
```
**Output:**
```
2
```

---

## 2. Longest Substring with All Distinct Characters
A problem that introduces character uniqueness optimization and teaches sliding window techniques using hash-based duplicate detection for maximum substring length finding with distinctness constraints.

Given a string, find the length of the **longest substring** without **repeating characters** using sliding window with character tracking. This operation is fundamental in **string optimization** and **uniqueness analysis** where you need to **maximize substring length** while maintaining character distinctness efficiently. The technique uses **variable sliding window** with hash-based character tracking to detect duplicates and contract window appropriately. This concept is essential in **text processing**, **data validation**, and **pattern analysis** where finding longest unique segments enables content analysis and string optimization in text-based applications.

This introduces **uniqueness constraint algorithms** and **character tracking techniques** that are crucial for **string optimization and efficient distinctness analysis operations**.

**Your task:** Implement sliding window with hash-based character tracking to find maximum length substrings maintaining complete character uniqueness.

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

---

## 3. Binary Subarray with Sum
A problem that teaches binary array analysis and demonstrates counting algorithms using prefix sum techniques for goal-based subarray enumeration in binary data structures.

Given a **binary array** and an integer **goal**, return the **number of non-empty subarrays** with **sum equal to goal** using prefix sum counting approach. This operation is fundamental in **binary data analysis** and **pattern counting** where you need to **enumerate all segments** meeting specific sum criteria efficiently. The technique uses **prefix sum frequency tracking** to count how many previous sums enable current position to achieve the goal sum. This concept is essential in **binary signal processing**, **digital analysis**, and **statistical counting** where enumerating binary patterns meeting criteria enables frequency analysis and pattern recognition in digital data streams.

This teaches **binary pattern counting algorithms** and **prefix sum enumeration techniques** that are essential for **binary analysis and efficient subarray counting operations**.

**Your task:** Implement prefix sum frequency counting to enumerate all binary subarrays meeting goal sum requirements through efficient pattern analysis.

### Examples

**Input:**
```
nums = [1,0,1,0,1], goal = 2
```
**Output:**
```
4
```

---

**Input:**
```
nums = [0,0,0,0,0], goal = 0
```
**Output:**
```
15
```
