<h2 align="center">Day 66 (20/08/2025)</h2>

## 1. Minimum Platforms at Railway Station
A problem that demonstrates resource allocation optimization and teaches interval overlap analysis using greedy approach for efficient infrastructure planning and scheduling operations.

Given **arrival and departure times** of trains, find the **minimum number of platforms** needed so that **no train waits** using interval management techniques. This operation is fundamental in **resource scheduling** and **capacity planning** where you need to **optimize infrastructure utilization** to handle overlapping demands efficiently. The technique uses **event-based greedy approach** by processing arrival and departure events chronologically, maintaining active train count to determine peak platform requirements. This concept is essential in **transportation systems**, **server allocation**, and **meeting room scheduling** where minimizing resources while satisfying all demands enables cost-effective operations and optimal facility utilization in high-traffic environments.

This demonstrates **interval overlap algorithms** and **resource optimization techniques** that are crucial for **capacity planning and efficient infrastructure management operations**.

**Your task:** Implement greedy platform allocation using event-based chronological processing to minimize required platforms while ensuring no scheduling conflicts.

### Examples

**Input:**
```
arr = [900, 940, 950, 1100, 1500, 1800], dep = [910, 1200, 1120, 1130, 1900, 2000]
```
**Output:**
```
3
```

---

**Input:**
```
arr = [100, 200, 300], dep = [150, 250, 350]
```
**Output:**
```
1
```

---

## 2. Buy and Sell Stocks (Once)
A problem that introduces profit maximization techniques and teaches single-pass optimization algorithms using greedy approach for efficient trading strategy and financial analysis operations.

Given **stock prices** over time, find the **best day to buy and sell** to achieve **maximum profit** with single transaction constraint. This operation is fundamental in **trading optimization** and **financial analysis** where you need to **identify optimal entry and exit points** for maximum return efficiently. The technique uses **minimum price tracking greedy approach** to maintain the lowest buying price seen so far while calculating maximum profit at each selling opportunity. This concept is essential in **investment strategies**, **arbitrage opportunities**, and **market analysis** where timing decisions enable profit maximization and risk management in dynamic financial markets with price volatility.

This introduces **trading optimization algorithms** and **profit maximization techniques** that are essential for **financial analysis and efficient investment strategy operations**.

**Your task:** Implement greedy stock trading using minimum price tracking to identify optimal buy-sell timing for maximum single-transaction profit.

### Examples

**Input:**
```
prices = [7, 1, 5, 3, 6, 4]
```
**Output:**
```
5
```

---

**Input:**
```
prices = [7, 6, 4, 3, 1]
```
**Output:**
```
0 (no profit)
```

---

## 3. Distribute Candies Fairly
A problem that teaches constraint satisfaction optimization and demonstrates neighbor-aware distribution algorithms using greedy approach with bidirectional scanning for fair resource allocation operations.

Given **children's ratings**, distribute **candies** such that **children with higher ratings** get **more candies than neighbors** using constraint-based optimization. This operation is fundamental in **fair distribution** and **constraint satisfaction** where you need to **satisfy relative ordering requirements** while minimizing total resources efficiently. The technique uses **two-pass greedy approach** scanning left-to-right and right-to-left to ensure each child receives more candies than lower-rated neighbors while maintaining minimum distribution. This concept is essential in **reward systems**, **salary structures**, and **resource allocation** where maintaining fairness while optimizing costs enables equitable distribution and efficient resource management in hierarchical systems.

This teaches **constraint satisfaction algorithms** and **bidirectional optimization techniques** that are crucial for **fair distribution and efficient resource allocation operations**.

**Your task:** Implement greedy candy distribution using bidirectional scanning to satisfy rating constraints while minimizing total candy allocation.

### Examples

**Input:**
```
ratings = [1, 0, 2]
```
**Output:**
```
5
```

---

**Input:**
```
ratings = [1, 2, 2]
```
**Output:**
```
4
```
