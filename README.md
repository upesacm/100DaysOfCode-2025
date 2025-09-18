<h2 align="center">Day 96 (19/09/2025)</h2>

## 1. 0/1 Knapsack
A problem that demonstrates resource optimization and teaches bounded selection dynamic programming using weight-value constraints for efficient capacity utilization and optimal item selection operations.

Given **items with weights and values** and a **knapsack capacity W**, find the **maximum value** achievable without exceeding weight limit using DP strategy. This operation is fundamental in **resource allocation** and **optimization problems** where you need to **maximize benefit under constraints** for efficient decision making. The technique uses **2D DP** where dp[i][w] represents maximum value using first i items with weight limit w, considering include/exclude decisions for each item. This concept is essential in **portfolio management**, **resource planning**, and **budget optimization** where capacity constraints enable efficient value maximization and optimal selection-based resource allocation in bounded systems.

This demonstrates **bounded knapsack DP** and **constraint optimization techniques** that are crucial for **capacity-limited maximization and efficient resource selection operations**.

**Your task:** Implement 2D dynamic programming to solve 0/1 knapsack problem with weight constraints and value optimization.

### Examples

**Input:**
```
Items: weights=[1,3,4,5], values=[1,4,5,7], W=7

2D DP Table Construction:
Items\Weight  0  1  2  3  4  5  6  7
     0       0  0  0  0  0  0  0  0  (no items)
     1(w=1,v=1) 0  1  1  1  1  1  1  1  (item 1 only)
     2(w=3,v=4) 0  1  1  4  5  5  5  5  (items 1,2)
     3(w=4,v=5) 0  1  1  4  5  6  6  9  (items 1,2,3)
     4(w=5,v=7) 0  1  1  4  5  7  8  9  (all items)

Optimal selection analysis:
At dp[4][7]: Consider item 4 (w=5,v=7)
- Include: 7 + dp[3][7-5] = 7 + dp[3][2] = 7 + 1 = 8
- Exclude: dp[3][7] = 9
- Choose max(8,9) = 9

Optimal subset: items 2 and 3 (weights: 3+4=7, values: 4+5=9)

Visual representation:
Items: [w=1,v=1] [w=3,v=4] [w=4,v=5] [w=5,v=7]
Select:    ✗        ✓        ✓        ✗
Total weight: 3+4 = 7 ≤ 7 ✓
Total value: 4+5 = 9
```
**Output:**
```
9
```

---

**Input:**
```
Items: weights=[4,5,1], values=[1,2,3], W=4

2D DP Table Construction:
Items\Weight  0  1  2  3  4
     0       0  0  0  0  0  (no items)
     1(w=4,v=1) 0  0  0  0  1  (item 1 only)
     2(w=5,v=2) 0  0  0  0  1  (items 1,2 - item 2 too heavy)
     3(w=1,v=3) 0  3  3  3  3  (all items - item 3 fits)

Optimal selection analysis:
Item 3 (w=1,v=3) fits within capacity W=4
Items 1 and 2 are too heavy to combine with item 3

Optimal subset: item 3 only (weight: 1, value: 3)

Visual representation:
Items: [w=4,v=1] [w=5,v=2] [w=1,v=3]  
Select:    ✗        ✗        ✓
Total weight: 1 ≤ 4 ✓
Total value: 3
```
**Output:**
```
3
```

---

## 2. Subset Sum
A problem that introduces boolean satisfiability and teaches existence-based dynamic programming using target sum verification for efficient combinatorial checking and optimal subset detection operations.

Given an **integer array and target sum**, determine if there exists a **subset with sum equal to target** using DP strategy. This operation is fundamental in **combinatorial analysis** and **decision problems** where you need to **verify sum achievability** for constraint satisfaction efficiently. The technique uses **2D boolean DP** where dp[i][sum] indicates if target sum is achievable using first i elements, with recurrence considering include/exclude decisions. This concept is essential in **budget planning**, **load balancing**, and **partition problems** where sum verification enables efficient feasibility checking and optimal subset-based constraint satisfaction in combinatorial systems.

This introduces **boolean DP** and **existence verification techniques** that are essential for **subset detection and efficient sum satisfiability operations**.

**Your task:** Implement boolean dynamic programming to check if subset with target sum exists in given array.

### Examples

**Input:**
```
Array: [3,34,4,12,5,2], target=9

2D Boolean DP Table:
Elements\Sum  0  1  2  3  4  5  6  7  8  9
     []      T  F  F  F  F  F  F  F  F  F  (empty set)
     [3]     T  F  F  T  F  F  F  F  F  F
     [3,34]  T  F  F  T  F  F  F  F  F  F  (34 too large)
     [3,34,4] T  F  F  T  T  F  F  T  F  F  (3+4=7)
     [3,34,4,12] T F F T T F F T F F  (no new combinations ≤9)
     [3,34,4,12,5] T F F T T T F T T T  (4+5=9 ✓)

Sum 9 achievable: dp[5][9] = True

Subset construction:
Working backwards from dp[5][9] = True:
- Element 5: 9-5=4, check dp[4][4] = True → include 5
- Element 4: 4-4=0, check dp[3][0] = True → include 4  
- Elements 3,34,12: not needed

Valid subset: {4, 5} with sum = 4+5 = 9 ✓

Visual verification:
Array: [3, 34, 4, 12, 5, 2]
Select: ✗  ✗   ✓  ✗   ✓  ✗
Subset sum: 4 + 5 = 9 = target ✓
```
**Output:**
```
Yes
```

---

**Input:**
```
Array: [1,2,3], target=7

2D Boolean DP Table:
Elements\Sum  0  1  2  3  4  5  6  7
     []      T  F  F  F  F  F  F  F  (empty set)
     [1]     T  T  F  F  F  F  F  F
     [1,2]   T  T  T  T  F  F  F  F  (1+2=3)
     [1,2,3] T  T  T  T  T  T  T  F  (max: 1+2+3=6)

Sum 7 not achievable: dp[3][7] = False

Analysis:
Maximum possible sum = 1+2+3 = 6 < 7
No subset can achieve target sum of 7

Visual verification:
Array: [1, 2, 3]
Max sum: 1+2+3 = 6 < 7 = target ✗
```
**Output:**
```
No
```

---

## 3. Partition Equal Subset Sum
A problem that teaches set partitioning and demonstrates balanced division dynamic programming using equal sum verification for efficient array splitting and optimal partition detection operations.

Given an **integer array**, determine if it can be **partitioned into two subsets with equal sum** using subset sum DP strategy. This operation is fundamental in **load balancing** and **fair division** where you need to **split resources equally** for balanced distribution efficiently. The technique reduces to **subset sum problem** where target equals half of total sum, using boolean DP to verify if half-sum subset exists. This concept is essential in **task scheduling**, **resource distribution**, and **game balancing** where equal partitioning enables efficient workload division and optimal balance-based allocation in splitting systems.

This teaches **partition reduction** and **balanced splitting techniques** that are crucial for **equal division and efficient set partitioning operations**.

**Your task:** Implement subset sum DP to check if array can be partitioned into two equal-sum subsets.

### Examples

**Input:**
```
Array: [1,5,11,5]

Partition Analysis:
Total sum = 1+5+11+5 = 22
Target sum = 22/2 = 11 (must be integer)

Subset Sum DP for target=11:
Elements\Sum  0  1  2  3  4  5  6  7  8  9 10 11
     []      T  F  F  F  F  F  F  F  F  F  F  F
     [1]     T  T  F  F  F  F  F  F  F  F  F  F
     [1,5]   T  T  F  F  F  T  T  F  F  F  F  F
     [1,5,11] T  T  F  F  F  T  T  F  F  F  F  T  (11 alone)
     [1,5,11,5] T T F F F T T F F F T T  (5+5=10, 1+5+5=11)

Sum 11 achievable: dp[4][11] = True

Partition verification:
Subset 1: {11} → sum = 11
Subset 2: {1,5,5} → sum = 1+5+5 = 11
Equal sums ✓

Visual representation:
Array: [1, 5, 11, 5]
Part1:  ✗  ✗  ✓   ✗  → {11} = 11
Part2:  ✓  ✓  ✗   ✓  → {1,5,5} = 11
Equal partition possible ✓
```
**Output:**
```
Yes
```

---

**Input:**
```
Array: [1,2,3,5]

Partition Analysis:
Total sum = 1+2+3+5 = 11
Target sum = 11/2 = 5.5 (not integer)

Since total sum is odd, equal partition impossible.
No two subsets can have equal integer sums.

Mathematical proof:
If sum is odd, any partition results in:
- One subset with sum ⌊11/2⌋ = 5
- Other subset with sum ⌈11/2⌉ = 6
5 ≠ 6, so equal partition impossible

Visual representation:
Array: [1, 2, 3, 5]
Total sum: 11 (odd) → Equal partition impossible ✗
```
**Output:**
```
No
```
