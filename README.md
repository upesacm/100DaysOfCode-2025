<h2 align="center">Day 95 (18/09/2025)</h2>

## 1. Unique Paths in Grid
A problem that demonstrates combinatorial path counting and teaches grid traversal dynamic programming using directional constraints for efficient route enumeration and optimal navigation analysis operations.

Given **grid dimensions m×n**, find the **number of unique paths** from top-left to bottom-right when you can only move **right or down** using DP strategy. This operation is fundamental in **combinatorial counting** and **path analysis** where you need to **enumerate all possible routes** with movement restrictions efficiently. The technique uses **2D DP** where each cell represents number of ways to reach that position, with recurrence dp[i][j] = dp[i-1][j] + dp[i][j-1]. This concept is essential in **robotics navigation**, **game pathfinding**, and **probability analysis** where counting valid paths enables efficient route planning and optimal movement-based decision making in grid-based systems.

This demonstrates **combinatorial DP** and **grid traversal techniques** that are crucial for **path enumeration and efficient route counting operations**.

**Your task:** Implement dynamic programming to count all unique paths in grid with right-down movement constraints.

### Examples

**Input:**
```
Grid dimensions: m=3, n=7 (3 rows, 7 columns)

DP Grid Visualization:
     0  1  2  3  4  5  6
  0  1  1  1  1  1  1  1  (only one way to reach top row)
  1  1  2  3  4  5  6  7  (ways = left + up)
  2  1  3  6 10 15 21 28  (ways = left + up)

Step-by-step calculation:
Row 0: All positions = 1 (only right moves)
Col 0: All positions = 1 (only down moves)

For position (1,1): dp[1][1] = dp[0][1] + dp[1][0] = 1 + 1 = 2
For position (1,2): dp[1][2] = dp[0][2] + dp[1][1] = 1 + 2 = 3
...
For position (2,6): dp[2][6] = dp[1][6] + dp[2][5] = 7 + 21 = 28

Total unique paths from (0,0) to (2,6): 28
```
**Output:**
```
28
```

---

**Input:**
```
Grid dimensions: m=3, n=2 (3 rows, 2 columns)

DP Grid Visualization:
     0  1
  0  1  1  (top row: only right moves)
  1  1  2  (ways = 1 + 1 = 2)
  2  1  3  (ways = 1 + 2 = 3)

All possible paths visualization:
Path 1: (0,0) → (0,1) → (1,1) → (2,1)  [Right, Down, Down]
Path 2: (0,0) → (1,0) → (1,1) → (2,1)  [Down, Right, Down]  
Path 3: (0,0) → (1,0) → (2,0) → (2,1)  [Down, Down, Right]

Total unique paths: 3
```
**Output:**
```
3
```

---

## 2. Unique Paths with Obstacles
A problem that introduces constraint-based path counting and teaches obstacle-aware dynamic programming using blocked cell handling for efficient navigation planning and restricted route analysis operations.

Given a **grid with obstacles (1=blocked, 0=free)**, find the **number of unique paths** from top-left to bottom-right using obstacle-avoiding DP strategy. This operation is fundamental in **constrained navigation** and **blocked path analysis** where you need to **count valid routes avoiding obstacles** for realistic pathfinding efficiently. The technique uses **modified 2D DP** where blocked cells have 0 paths and free cells accumulate paths from accessible neighbors. This concept is essential in **robot navigation**, **maze solving**, and **route optimization** where obstacle avoidance enables efficient path planning and optimal navigation in restricted grid environments.

This introduces **constraint-aware DP** and **obstacle handling techniques** that are essential for **restricted path counting and efficient obstacle-aware navigation operations**.

**Your task:** Implement obstacle-aware dynamic programming to count paths while avoiding blocked cells in the grid.

### Examples

**Input:**
```
Grid with obstacles:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

DP Grid Analysis:
     0  1  2
  0  1  1  1  (top row: no obstacles)
  1  1  0  1  (middle: obstacle blocks dp[1][1] = 0)
  2  1  1  2  (bottom: dp[2][2] = dp[1][2] + dp[2][1] = 1 + 1 = 2)

Visual path representation:
Grid:    Paths:
0 0 0    1 1 1
0 X 0 →  1 0 1  (X = obstacle, blocks all paths through it)
0 0 0    1 1 2

Valid paths:
Path 1: (0,0) → (0,1) → (0,2) → (1,2) → (2,2)  [R,R,D,D]
Path 2: (0,0) → (1,0) → (2,0) → (2,1) → (2,2)  [D,D,R,R]

Total unique paths: 2
```
**Output:**
```
2
```

---

**Input:**
```
Grid with obstacles:
[[0,1],
 [0,0]]

DP Grid Analysis:
     0  1
  0  1  0  (obstacle at (0,1) blocks path)
  1  1  1  (dp[1][1] = dp[0][1] + dp[1][0] = 0 + 1 = 1)

Visual representation:
Grid:    Paths:
0 X      1 0   (X = obstacle at (0,1))
0 0  →   1 1

Only one valid path:
Path: (0,0) → (1,0) → (1,1)  [Down, Right]

Total unique paths: 1
```
**Output:**
```
1
```

---

## 3. Minimum Path Sum
A problem that teaches cost optimization and demonstrates weighted grid dynamic programming using minimum selection strategy for efficient route cost minimization and optimal path value operations.

Given a **grid with positive integers**, find the **minimum sum path** from top-left to bottom-right using cost-minimizing DP strategy. This operation is fundamental in **cost optimization** and **weighted pathfinding** where you need to **minimize total path cost** for resource-efficient navigation. The technique uses **2D DP** where each cell stores minimum sum to reach that position, with recurrence dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]). This concept is essential in **logistics optimization**, **resource allocation**, and **travel planning** where minimizing path costs enables efficient route selection and optimal cost-based navigation in weighted grid systems.

This teaches **cost optimization DP** and **minimum path techniques** that are crucial for **weighted pathfinding and efficient cost minimization operations**.

**Your task:** Implement cost-minimizing dynamic programming to find minimum sum path through weighted grid.

### Examples

**Input:**
```
Grid with costs:
[[1,3,1],
 [1,5,1],
 [4,2,1]]

DP Cost Analysis:
Step-by-step minimum cost calculation:
     0  1  2
  0  1  4  5  (cumulative: 1, 1+3=4, 4+1=5)
  1  2  7  6  (min: 1+1=2, min(4,2)+5=7, min(5,7)+1=6)
  2  6  8  7  (min: 2+4=6, min(7,6)+2=8, min(6,8)+1=7)

Path reconstruction:
Minimum path: (0,0)→(0,1)→(0,2)→(1,2)→(2,2)
Cost breakdown: 1 → 3 → 1 → 1 → 1 = 7

Visual path representation:
Grid:       DP Costs:    Optimal Path:
1 3 1       1 4 5        ✓ ✓ ✓
1 5 1   →   2 7 6    →   ✗ ✗ ✓
4 2 1       6 8 7        ✗ ✗ ✓

Total minimum cost: 7
```
**Output:**
```
7
```

---

**Input:**
```
Grid with costs:
[[1,2,3],
 [4,5,6]]

DP Cost Analysis:
     0  1  2
  0  1  3  6  (cumulative: 1, 1+2=3, 3+3=6)
  1  5  8 12  (min: 1+4=5, min(3,5)+5=8, min(6,8)+6=12)

Path reconstruction:
Only one possible minimum path due to grid shape:
Path: (0,0)→(0,1)→(0,2)→(1,2)
Cost: 1 → 2 → 3 → 6 = 12

Visual representation:
Grid:       DP Costs:    Optimal Path:
1 2 3       1 3 6        ✓ ✓ ✓
4 5 6   →   5 8 12   →   ✗ ✗ ✓

Total minimum cost: 12
```
**Output:**
```
12
```
