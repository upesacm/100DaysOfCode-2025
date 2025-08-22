<h2 align="center">Day 68 (22/08/2025)</h2>

## 1. Min Jumps to Reach End
A problem that demonstrates jump optimization techniques and teaches range-based greedy algorithms using maximum reach calculation for efficient path traversal and movement minimization operations.

Given an **array where each element represents maximum jump distance**, find the **minimum number of jumps** to reach the **end position** using greedy range optimization strategy. This operation is fundamental in **path optimization** and **movement planning** where you need to **minimize steps** while maximizing coverage efficiently. The technique uses **greedy maximum reach approach** that tracks the farthest reachable position at each step, making jumps only when necessary to extend reach beyond current range. This concept is essential in **game pathfinding**, **route planning**, and **resource traversal** where minimizing moves while ensuring progress enables efficient navigation and optimal movement strategies in constrained environments.

This demonstrates **jump optimization algorithms** and **range-based traversal techniques** that are crucial for **path planning and efficient movement minimization operations**.

**Your task:** Implement greedy jump optimization using maximum reach tracking to minimize required jumps while ensuring end position reachability.

### Examples

**Input:**
```
arr = [2, 3, 1, 1, 4]
```
**Output:**
```
2
```

---

**Input:**
```
arr = [1, 1, 1, 1]
```
**Output:**
```
3
```

---

## 2. Rearrange Characters (Greedy Frequency)
A problem that introduces frequency-based optimization and teaches priority-based arrangement algorithms using greedy approach for efficient character distribution and constraint satisfaction operations.

Given a **string**, rearrange characters so that **no two identical characters are adjacent** using frequency-based greedy scheduling strategy. This operation is fundamental in **constraint satisfaction** and **sequence arrangement** where you need to **distribute elements optimally** while avoiding conflicts efficiently. The technique uses **max-heap frequency greedy approach** to always place the most frequent remaining character, followed by the next most frequent to avoid adjacency, ensuring balanced distribution. This concept is essential in **task scheduling**, **resource allocation**, and **load balancing** where preventing clustering while maintaining availability enables smooth operations and optimal distribution in constraint-based systems.

This introduces **frequency-based scheduling algorithms** and **constraint satisfaction techniques** that are essential for **character arrangement and efficient distribution optimization operations**.

**Your task:** Implement greedy character rearrangement using frequency-based priority scheduling to achieve non-adjacent placement with optimal character distribution.

### Examples

**Input:**
```
"aab"
```
**Output:**
```
"aba"
```

---

**Input:**
```
"aaab"
```
**Output:**
```
""
```

---

## 3. Max Sum After K Negations
A problem that teaches sign optimization techniques and demonstrates value maximization algorithms using greedy approach with selective negation for efficient sum enhancement operations.

Given an **array and K operations**, flip **up to K numbers** to **maximize the total sum** using strategic negation optimization approach. This operation is fundamental in **value maximization** and **sign optimization** where you need to **enhance total value** through selective modifications efficiently. The technique uses **greedy negative-first approach** by prioritizing negation of most negative numbers first, then handling remaining operations on smallest absolute values to maximize benefit. This concept is essential in **profit optimization**, **score maximization**, and **financial adjustments** where strategic value modifications enable sum enhancement and optimal return generation in constrained operation scenarios.

This teaches **sign optimization algorithms** and **value maximization techniques** that are crucial for **sum enhancement and efficient negation strategy operations**.

**Your task:** Implement greedy negation strategy using priority-based value selection to maximize sum through optimal K-operation utilization.

### Examples

**Input:**
```
nums = [4, 2, 3], k = 1
```
**Output:**
```
5
```

---

**Input:**
```
nums = [3, -1, 0, 2], k = 3
```
**Output:**
```
6
```
