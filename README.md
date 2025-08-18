<h2 align="center">Day 64 (18/08/2025)</h2>

## 1. Select Maximum Activities
A problem that demonstrates activity selection optimization and teaches interval scheduling algorithms using greedy approach for efficient resource allocation and time management operations.

Given **start and end times** of activities, find the **maximum number of non-overlapping activities** you can perform using greedy selection strategy. This operation is fundamental in **interval scheduling** and **resource optimization** where you need to **maximize activity participation** within time constraints efficiently. The technique uses **earliest finish time greedy approach** to always select activities that end first, as this leaves maximum room for subsequent activities. This concept is essential in **project management**, **meeting scheduling**, and **resource allocation** where maximizing concurrent operations enables optimal time utilization and efficient workflow management in time-sensitive environments.

This demonstrates **activity selection algorithms** and **interval scheduling techniques** that are crucial for **resource optimization and efficient time management operations**.

**Your task:** Implement greedy activity selection using earliest finish time strategy to maximize non-overlapping activity participation with optimal scheduling.

### Examples

**Input:**
```
start = [1, 3, 0, 5, 8, 5]
end = [2, 4, 6, 7, 9, 9]
```
**Output:**
```
4
```

---

**Input:**
```
start = [1, 2, 3]
end = [2, 3, 4]
```
**Output:**
```
3
```

---

## 2. Fractional Knapsack
A problem that introduces fractional optimization techniques and teaches value-density based selection algorithms using greedy approach for efficient capacity utilization and profit maximization operations.

Given **weights and values** of items with **bag capacity**, find the **maximum total value** by taking **fractional portions** of items using value-density optimization. This operation is fundamental in **resource allocation** and **profit maximization** where you need to **optimize value extraction** within capacity constraints efficiently. The technique uses **value-to-weight ratio greedy approach** to prioritize items with highest value density, taking full items when possible and fractional amounts when needed. This concept is essential in **investment optimization**, **cargo loading**, and **portfolio management** where maximizing value within constraints enables efficient resource distribution and optimal return generation in capacity-limited scenarios.

This introduces **fractional optimization algorithms** and **value-density maximization techniques** that are essential for **capacity optimization and efficient profit maximization operations**.

**Your task:** Implement greedy fractional knapsack using value-density ratios to achieve optimal capacity utilization with maximum value extraction.

### Examples

**Input:**
```
weights = [10, 20, 30], values = [60, 100, 120], capacity = 50
```
**Output:**
```
240.0
```

---

**Input:**
```
weights = [5, 10], values = [50, 60], capacity = 10
```
**Output:**
```
80.0
```

---

## 3. Job Scheduling for Profit
A problem that teaches deadline-aware optimization and demonstrates profit-based scheduling algorithms using greedy approach with union-find structures for efficient job sequencing operations.

Given **jobs with deadlines and profits**, find the **optimal job sequence** for **maximum profit** using deadline-aware greedy selection. This operation is fundamental in **task scheduling** and **profit optimization** where you need to **maximize earnings** within deadline constraints efficiently. The technique uses **profit-based greedy approach** combined with union-find or slot-based allocation to ensure jobs are scheduled before their deadlines while maximizing total profit. This concept is essential in **project management**, **manufacturing scheduling**, and **service optimization** where meeting deadlines while maximizing profit enables efficient business operations and optimal resource utilization in deadline-critical environments.

This teaches **deadline-aware scheduling algorithms** and **profit optimization techniques** that are crucial for **job sequencing and efficient profit maximization operations**.

**Your task:** Implement greedy job scheduling using profit-based selection with deadline management to achieve optimal job sequencing with maximum profit generation.

### Examples

**Input:**
```
jobs = [(1, 4, 20), (2, 1, 10), (3, 1, 40), (4, 1, 30)]
```
**Output:**
```
2 jobs, Profit: 60
```

---

**Input:**
```
jobs = [(1, 2, 100), (2, 1, 19), (3, 2, 27)]
```
**Output:**
```
2 jobs, Profit: 127
```
