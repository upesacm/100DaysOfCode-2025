<h2 align="center">Day 52 (06/08/2025)</h2>

## 1. Check Array for Pair with Sum
A problem that introduces two-pointer optimization techniques and teaches efficient pair finding algorithms using sorted array properties for target sum detection and array analysis operations.

Given a sorted array and a number **x**, check if there exists a **pair of elements** whose **sum is exactly x** using two-pointer technique. This operation is fundamental in **pair searching** and **target sum problems** where you need to **find complementary elements** efficiently within sorted datasets. The technique uses **two-pointer convergence** from array ends to eliminate the need for nested loops, reducing time complexity from O(n²) to O(n). This concept is essential in **algorithmic optimization**, **data analysis**, and **search problems** where finding element pairs that meet specific criteria enables efficient problem solving and reduces computational overhead in large datasets.

This teaches **two-pointer algorithms** and **sorted array optimization techniques** that are essential for **pair finding and efficient target sum detection operations**.

**Your task:** Implement two-pointer convergence on sorted arrays to efficiently detect pairs with target sums using optimal time complexity.

### Examples

**Input:**
```
arr = [1, 4, 45, 6, 10, 8], x = 16
```
**Output:**
```
true
```

---

**Input:**
```
arr = [1, 2, 4, 3, 6], x = 10
```
**Output:**
```
false
```

---

## 2. Find All Pairs with Given Difference
A problem that demonstrates systematic pair enumeration and teaches difference-based searching algorithms using hash-based or two-pointer methods for comprehensive pair analysis operations.

Given an array and a value **k**, find **all pairs** with **difference k** using efficient searching techniques. This operation is fundamental in **difference analysis** and **pair enumeration** where you need to **identify all element relationships** that meet specific difference criteria. The technique can use **hash-based lookup** or **sorted array traversal** to find all pairs efficiently while avoiding duplicate combinations. This concept is essential in **statistical analysis**, **data comparison**, and **relationship mapping** where finding all pairs with specific differences enables comprehensive data analysis and pattern recognition in numerical datasets.

This introduces **comprehensive pair finding algorithms** and **difference-based search techniques** that are crucial for **relationship analysis and efficient pair enumeration operations**.

**Your task:** Implement systematic pair finding using hash-based lookup or sorted traversal to identify all pairs meeting difference criteria comprehensively.

### Examples

**Input:**
```
arr = [1, 5, 3, 4, 2], k = 2
```
**Output:**
```
[(1, 3), (3, 5), (5, 3), (4, 2)]
```

---

**Input:**
```
arr = [8, 12, 16, 4, 0, 20], k = 4
```
**Output:**
```
[(8, 12), (12, 16), (16, 20)]
```

---

## 3. Trapping Rain Water
A problem that teaches advanced two-pointer techniques and demonstrates elevation-based computation algorithms using height analysis for geometric calculation and optimization problems.

Given **n non-negative integers** representing an elevation map, compute **how much water** it can trap after raining using two-pointer technique. This operation is fundamental in **geometric computation** and **area calculation** where you need to **analyze elevation profiles** and calculate trapped volumes efficiently. The technique uses **two-pointer approach** with height tracking to determine water levels at each position based on surrounding elevation barriers. This concept is essential in **civil engineering**, **terrain analysis**, and **computational geometry** where calculating trapped volumes enables water management planning and geometric optimization in elevation-based scenarios.

This teaches **geometric computation algorithms** and **elevation analysis techniques** that are essential for **volume calculation and efficient geometric optimization operations**.

**Your task:** Implement two-pointer elevation analysis to calculate trapped water volumes by tracking maximum heights and computing water levels efficiently.

### Examples

**Input:**
```
height = [0,1,0,2,1,0,1,3,2,1,2,1]
```
**Output:**
```
6
```

---

**Input:**
```
height = [4,2,0,3,2,5]
```
**Output:**
```
9
```
