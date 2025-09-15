<h2 align="center">Day 93 (16/09/2025)</h2>

## 1. House Robber
A problem that demonstrates constraint-based optimization and teaches non-adjacent selection dynamic programming using maximum profit strategy for efficient resource extraction and conflict avoidance operations.

Given an **array of house values**, find the **maximum amount you can rob** without robbing **two adjacent houses** using DP strategy. This operation is fundamental in **constrained optimization** and **selection problems** where you need to **maximize profit with adjacency restrictions** for optimal resource allocation efficiently. The technique uses **DP with state tracking** where each position stores maximum loot possible up to that house, considering both rob and skip decisions. This concept is essential in **resource scheduling**, **conflict resolution**, and **optimization with constraints** where adjacency limitations enable efficient profit maximization and optimal selection in restricted choice systems.

This demonstrates **constraint-based DP** and **selection optimization techniques** that are crucial for **maximum profit extraction and efficient conflict-free optimization operations**.

**Your task:** Implement dynamic programming to find maximum robbery amount while avoiding adjacent house selections.

### Examples

**Input:**
```
Houses: [1, 2, 3, 1]

DP Decision Analysis:
House 0 (value=1): Rob it → max_loot = 1
House 1 (value=2): Skip house 0, rob house 1 → max_loot = 2  
House 2 (value=3): Rob house 0+2 or just house 1?
         Option 1: house[0] + house[2] = 1 + 3 = 4
         Option 2: house[1] only = 2
         Choose max → max_loot = 4
House 3 (value=1): house[1] + house[3] = 2 + 1 = 3 vs current max 4
         Keep max_loot = 4

Visual representation:
[1, 2, 3, 1]
 ✓  ✗  ✓  ✗  → Rob houses 0,2 = 1+3 = 4

DP Array: [1, 2, 4, 4]
```
**Output:**
```
4
```

---

**Input:**
```
Houses: [2, 7, 9, 3, 1]

DP Decision Analysis:
House 0 (value=2): max_loot = 2
House 1 (value=7): max_loot = max(2, 7) = 7
House 2 (value=9): max_loot = max(7, 2+9) = 11  
House 3 (value=3): max_loot = max(11, 7+3) = 11
House 4 (value=1): max_loot = max(11, 11+1) = 12

Visual representation:
[2, 7, 9, 3, 1]
 ✓  ✗  ✓  ✗  ✓  → Rob houses 0,2,4 = 2+9+1 = 12

DP Array: [2, 7, 11, 11, 12]
```
**Output:**
```
12
```

---

## 2. Maximum Subarray Sum (Kadane's Algorithm)
A problem that introduces sliding window optimization and teaches contiguous sum maximization using greedy dynamic programming for efficient subarray analysis and optimal segment identification operations.

Given an **integer array**, find the **maximum sum of any contiguous subarray** using Kadane's algorithm strategy. This operation is fundamental in **sequence analysis** and **range optimization** where you need to **find optimal contiguous segment** for maximum value extraction efficiently. The technique uses **single-pass DP** that maintains current subarray sum and global maximum, deciding at each position whether to extend current subarray or start fresh. This concept is essential in **financial analysis**, **signal processing**, and **data analytics** where finding peak performance segments enables efficient trend identification and optimal period-based analysis in sequential data systems.

This introduces **greedy DP algorithms** and **sliding optimization techniques** that are essential for **contiguous sum maximization and efficient subarray analysis operations**.

**Your task:** Implement Kadane's algorithm to find maximum sum contiguous subarray using single-pass dynamic programming approach.

### Examples

**Input:**
```
Array: [-2, 1, -3, 4, -1, 2, 1, -5, 4]

Kadane's Algorithm Step-by-step:
Index 0: current_sum = -2, max_sum = -2
Index 1: current_sum = max(1, -2+1) = 1, max_sum = 1
Index 2: current_sum = max(-3, 1-3) = -2, max_sum = 1  
Index 3: current_sum = max(4, -2+4) = 4, max_sum = 4
Index 4: current_sum = max(-1, 4-1) = 3, max_sum = 4
Index 5: current_sum = max(2, 3+2) = 5, max_sum = 5
Index 6: current_sum = max(1, 5+1) = 6, max_sum = 6
Index 7: current_sum = max(-5, 6-5) = 1, max_sum = 6
Index 8: current_sum = max(4, 1+4) = 5, max_sum = 6

Maximum subarray visualization:
[-2, 1, -3, [4, -1, 2, 1], -5, 4]
              ↑____________↑
              Maximum sum = 6

Subarray: [4, -1, 2, 1] = 4-1+2+1 = 6
```
**Output:**
```
6
```

---

**Input:**
```
Array: [1]

Single element analysis:
Index 0: current_sum = 1, max_sum = 1

Maximum subarray: [1]
Sum = 1
```
**Output:**
```
1
```

---

## 3. Coin Change (Min Coins)
A problem that teaches unbounded knapsack optimization and demonstrates minimum count dynamic programming using greedy selection strategy for efficient denomination combination and optimal change-making operations.

Given **coin denominations and target amount**, find the **minimum number of coins** needed to make the amount using DP strategy. This operation is fundamental in **combinatorial optimization** and **change-making problems** where you need to **minimize resource count** for exact value formation efficiently. The technique uses **bottom-up DP** where each amount stores minimum coins needed, considering all denominations and selecting optimal combinations. This concept is essential in **currency systems**, **resource allocation**, and **inventory management** where minimizing unit count enables efficient cost optimization and optimal denomination-based problem solving in monetary exchange systems.

This teaches **unbounded knapsack DP** and **minimum counting techniques** that are crucial for **change optimization and efficient denomination combination operations**.

**Your task:** Implement dynamic programming to find minimum coins needed for target amount using available denominations.

### Examples

**Input:**
```
Coins: [1, 2, 5]
Amount: 11

DP Table Construction:
Amount 0: 0 coins (base case)
Amount 1: min(dp[1-1]+1) = dp[0]+1 = 1 → [1]
Amount 2: min(dp[2-1]+1, dp[2-2]+1) = min(2, 1) = 1 → [2]  
Amount 3: min(dp[2]+1, dp[1]+1) = min(2, 2) = 2 → [2,1]
Amount 4: min(dp[3]+1, dp[2]+1) = min(3, 2) = 2 → [2,2]
Amount 5: min(dp[4]+1, dp[3]+1, dp[0]+1) = min(3, 3, 1) = 1 → [5]
...
Amount 11: min(dp[10]+1, dp[9]+1, dp[6]+1) = min(3, 3, 2) = 3

Optimal solution visualization:
11 = 5 + 5 + 1 (3 coins)

DP Array: [0, 1, 1, 2, 2, 1, 2, 2, 3, 3, 2, 3]
```
**Output:**
```
3
```

---

**Input:**
```
Coins: [2]
Amount: 3

DP Analysis:
Amount 0: 0 coins
Amount 1: No way (2 > 1) → impossible
Amount 2: dp[2-2]+1 = dp[0]+1 = 1 → [2]
Amount 3: dp[3-2]+1 = dp[1]+1 → impossible (dp[1] = ∞)

No valid combination:
Amount 3 cannot be formed using only coins of value 2

Result: No solution possible
```
**Output:**
```
-1
```
