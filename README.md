<h2 align="center">Day 65 (19/08/2025)</h2>

## 1. Minimum Coins
A problem that demonstrates coin change optimization and teaches denomination-based greedy algorithms using minimum selection strategy for efficient currency exchange and payment systems operations.

Given **coins of different denominations**, find the **minimum number of coins** to make a **given amount** using greedy denomination selection. This operation is fundamental in **currency optimization** and **payment processing** where you need to **minimize transaction components** while achieving target values efficiently. The technique uses **largest denomination first greedy approach** to select maximum value coins iteratively, reducing the total count of coins needed for amount formation. This concept is essential in **financial systems**, **vending machines**, and **cash register operations** where minimizing change components enables efficient transaction processing and optimal currency distribution in automated payment environments.

This demonstrates **coin change algorithms** and **denomination optimization techniques** that are crucial for **currency systems and efficient payment processing operations**.

**Your task:** Implement greedy coin selection using largest denomination priority to achieve minimum coin count for target amount formation.

### Examples

**Input:**
```
coins = [1, 2, 5, 10], amount = 23
```
**Output:**
```
5 (10+10+2+1)
```

---

**Input:**
```
coins = [1, 5, 6, 9], amount = 11
```
**Output:**
```
2 (5+6)
```

---

## 2. Maximum Chain of Pairs
A problem that introduces pair chaining optimization and teaches sequential selection algorithms using coordinate-based greedy approach for efficient sequence building and dependency management operations.

Given **coordinate pairs (a, b)**, find the **maximum number of chainable pairs** where each subsequent pair **(c, d)** satisfies **c > b** using greedy chaining strategy. This operation is fundamental in **sequence optimization** and **dependency resolution** where you need to **build longest valid chains** following ordering constraints efficiently. The technique uses **end-coordinate based greedy approach** to sort pairs by second element and select pairs that maintain the chaining property, maximizing chain length. This concept is essential in **scheduling systems**, **workflow management**, and **dependency graphs** where building maximum valid sequences enables optimal task ordering and efficient pipeline construction in constraint-based environments.

This introduces **pair chaining algorithms** and **sequence optimization techniques** that are essential for **dependency management and efficient chain building operations**.

**Your task:** Implement greedy pair chaining using end-coordinate sorting to achieve maximum valid pair sequence with optimal constraint satisfaction.

### Examples

**Input:**
```
pairs = [(5, 24), (15, 25), (27, 40), (50, 60)]
```
**Output:**
```
3
```

---

**Input:**
```
pairs = [(1, 2), (2, 3), (3, 4)]
```
**Output:**
```
2
```

---

## 3. Schedule Tasks Without Overlap
A problem that teaches overlap elimination optimization and demonstrates interval removal algorithms using greedy approach with minimal deletion strategy for efficient conflict resolution operations.

Given **start and end times** of tasks, **remove minimum tasks** to ensure **no overlapping intervals** using optimal elimination strategy. This operation is fundamental in **conflict resolution** and **schedule optimization** where you need to **minimize removals** while achieving non-overlapping arrangements efficiently. The technique uses **end-time based greedy approach** to sort intervals and remove conflicting tasks strategically, keeping maximum possible tasks while eliminating all overlaps. This concept is essential in **resource scheduling**, **meeting management**, and **system optimization** where minimizing disruptions while resolving conflicts enables efficient schedule maintenance and optimal resource utilization in multi-constraint environments.

This teaches **interval conflict resolution algorithms** and **minimal removal techniques** that are crucial for **schedule optimization and efficient overlap elimination operations**.

**Your task:** Implement greedy overlap elimination using minimal removal strategy to achieve maximum non-overlapping task retention with optimal conflict resolution.

### Examples

**Input:**
```
intervals = [(1, 2), (2, 3), (3, 4), (1, 3)]
```
**Output:**
```
Remove 1 → Remaining 3
```

---

**Input:**
```
intervals = [(1, 2), (1, 2), (1, 2)]
```
**Output:**
```
Remove 2 → Remaining 1
```
