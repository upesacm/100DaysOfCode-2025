<h2 align="center">Day 92 (15/09/2025)</h2>

## 1. Fibonacci Numbers (DP)
A problem that introduces dynamic programming fundamentals and teaches memoization optimization techniques using overlapping subproblems for efficient sequence generation and exponential complexity reduction operations.

Given an **integer N**, find the **Nth Fibonacci number** using dynamic programming strategy. This operation is fundamental in **sequence computation** and **optimization problems** where you need to **avoid redundant calculations** for mathematical series efficiently. The technique uses **bottom-up DP or memoization** to store previously computed values, transforming exponential recursive solution into linear time complexity. This concept is essential in **algorithm optimization**, **mathematical modeling**, and **performance enhancement** where eliminating repeated computations enables efficient sequence calculation and optimal resource utilization in recursive mathematical systems.

This demonstrates **memoization techniques** and **optimization principles** that are crucial for **sequence generation and efficient recursive problem solving operations**.

**Your task:** Implement dynamic programming approach to compute Fibonacci numbers efficiently, avoiding exponential time complexity of naive recursion.

### Examples

**Input:**
```
N = 5

Fibonacci Sequence Visualization:
F(0) = 0
F(1) = 1  
F(2) = F(1) + F(0) = 1 + 0 = 1
F(3) = F(2) + F(1) = 1 + 1 = 2
F(4) = F(3) + F(2) = 2 + 1 = 3
F(5) = F(4) + F(3) = 3 + 2 = 5

DP Array: [0, 1, 1, 2, 3, 5]
```
**Output:**
```
5
```

---

**Input:**
```
N = 7

Fibonacci Sequence Visualization:
F(0) = 0, F(1) = 1, F(2) = 1, F(3) = 2
F(4) = 3, F(5) = 5, F(6) = 8, F(7) = 13

Step-by-step calculation:
F(6) = F(5) + F(4) = 5 + 3 = 8
F(7) = F(6) + F(5) = 8 + 5 = 13

DP Array: [0, 1, 1, 2, 3, 5, 8, 13]
```
**Output:**
```
13
```

---

## 2. Climbing Stairs
A problem that demonstrates combinatorial counting and teaches step-based dynamic programming using path enumeration for efficient way-counting and discrete optimization operations.

Given **N steps**, find the **total number of ways** to reach the top when you can climb **1 or 2 steps at a time** using DP strategy. This operation is fundamental in **combinatorial problems** and **path counting** where you need to **enumerate all possible sequences** to reach a target efficiently. The technique uses **bottom-up DP** where each position represents ways to reach that step, with recurrence relation dp[i] = dp[i-1] + dp[i-2]. This concept is essential in **combinatorial optimization**, **game theory**, and **decision analysis** where counting valid sequences enables efficient probability calculation and optimal strategy enumeration in step-based progression systems.

This introduces **combinatorial DP** and **path counting techniques** that are essential for **way enumeration and efficient sequence counting operations**.

**Your task:** Implement dynamic programming to count all possible ways to climb N steps using 1 or 2 step combinations.

### Examples

**Input:**
```
N = 3

Step-by-step Analysis:
Ways to reach each step:
Step 0: 1 way (starting position)
Step 1: 1 way (one 1-step)
Step 2: 2 ways (1+1, or one 2-step)
Step 3: 3 ways (1+1+1, 1+2, 2+1)

Visual representation:
All possible paths to step 3:
Path 1: 1 → 1 → 1 (three 1-steps)
Path 2: 1 → 2 (1-step then 2-step)  
Path 3: 2 → 1 (2-step then 1-step)

DP Array: [1, 1, 2, 3]
```
**Output:**
```
3
```

---

**Input:**
```
N = 4

Step-by-step Analysis:
Ways to reach each step:
Step 0: 1, Step 1: 1, Step 2: 2, Step 3: 3
Step 4: ways(3) + ways(2) = 3 + 2 = 5

All possible paths to step 4:
Path 1: 1+1+1+1 (four 1-steps)
Path 2: 1+1+2 (two 1-steps, one 2-step)
Path 3: 1+2+1 (1-step, 2-step, 1-step)
Path 4: 2+1+1 (2-step, two 1-steps)
Path 5: 2+2 (two 2-steps)

DP Array: [1, 1, 2, 3, 5]
```
**Output:**
```
5
```

---

## 3. Minimum Cost Climbing Stairs
A problem that teaches cost optimization and demonstrates weighted path dynamic programming using minimum selection strategy for efficient resource minimization and optimal decision-making operations.

Given an **array of step costs**, find the **minimum cost to reach the top** when you can start from step 0 or 1 and climb 1 or 2 steps using cost-minimizing DP strategy. This operation is fundamental in **resource optimization** and **cost analysis** where you need to **find cheapest path** through weighted options efficiently. The technique uses **DP with cost accumulation** where each position stores minimum cost to reach that step, considering both possible previous positions. This concept is essential in **financial optimization**, **route planning**, and **resource allocation** where minimizing total cost enables efficient budget management and optimal cost-based decision making in weighted progression systems.

This teaches **cost optimization DP** and **minimum path techniques** that are crucial for **resource minimization and efficient cost-based optimization operations**.

**Your task:** Implement cost-minimizing dynamic programming to find cheapest way to reach the top of stairs with given step costs.

### Examples

**Input:**
```
Cost Array: [10, 15, 20]

Step-by-step Cost Analysis:
Step 0: cost 10 (can start here for free)
Step 1: cost 15 (can start here for free)
Step 2: cost 20
Top: no cost (destination)

Possible paths to top:
Path 1: Start at 0 → Step 2 → Top
Cost: 0 + 10 + 20 = 30

Path 2: Start at 1 → Top (2-step jump)  
Cost: 0 + 15 = 15

Path 3: Start at 0 → Step 1 → Top
Cost: 0 + 10 + 15 = 25

Minimum cost path: Start at 1 → Top = 15
```
**Output:**
```
15
```

---

**Input:**
```
Cost Array: [1,100,1,1,1,100,1,1,100,1]

DP Cost Analysis:
Position: 0  1  2  3  4   5  6  7   8  9  Top
Cost:    [1,100,1, 1, 1,100,1, 1,100, 1]
MinCost: [0, 0, 1, 2, 2,  3, 3, 4,  4, 5, 6]

Optimal path visualization:
Start→0(1)→2(1)→3(1)→4(1)→6(1)→7(1)→9(1)→Top
Total minimum cost: 1+1+1+1+1+1 = 6

Avoids expensive steps: 1(100), 5(100), 8(100)
```
**Output:**
```
6
```
