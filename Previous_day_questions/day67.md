<h2 align="center">Day 67 (21/08/2025)</h2>

## 1. Largest Number from Array
A problem that demonstrates custom sorting optimization and teaches lexicographic comparison algorithms using greedy approach for efficient string concatenation and numerical maximization operations.

Given a **list of numbers**, arrange them to form the **largest possible number** using custom comparison-based sorting strategy. This operation is fundamental in **lexicographic optimization** and **string manipulation** where you need to **maximize numerical value** through strategic ordering efficiently. The technique uses **custom comparator greedy approach** that compares concatenated results (a+b vs b+a) to determine optimal ordering, as traditional numerical sorting doesn't guarantee maximum concatenated value. This concept is essential in **data formatting**, **identifier generation**, and **optimization problems** where arranging elements strategically enables maximum value extraction and optimal sequence generation in string-based numerical systems.

This demonstrates **custom sorting algorithms** and **lexicographic optimization techniques** that are crucial for **string manipulation and efficient numerical maximization operations**.

**Your task:** Implement greedy number arrangement using custom concatenation comparator to achieve maximum possible numerical value from array elements.

### Examples

**Input:**
```
[10, 2]
```
**Output:**
```
"210"
```

---

**Input:**
```
[3, 30, 34, 5, 9]
```
**Output:**
```
"9534330"
```

---

## 2. Ropes with Minimum Cost
A problem that introduces cost minimization optimization and teaches heap-based aggregation algorithms using greedy approach for efficient resource combination and expense reduction operations.

Given **lengths of ropes**, connect them with the **least total cost** where cost equals **sum of lengths at each connection step** using min-heap optimization strategy. This operation is fundamental in **cost minimization** and **resource aggregation** where you need to **minimize cumulative expenses** through optimal combination sequence efficiently. The technique uses **min-heap greedy approach** to always combine the two shortest ropes first, as connecting shorter elements early reduces the cost impact on subsequent combinations. This concept is essential in **manufacturing processes**, **network design**, and **merger optimization** where strategic combination ordering enables cost reduction and efficient resource utilization in multi-stage operations.

This introduces **heap-based optimization algorithms** and **cost minimization techniques** that are essential for **resource combination and efficient expense reduction operations**.

**Your task:** Implement greedy rope connection using min-heap to always select shortest ropes for combination, achieving optimal cost minimization through strategic sequencing.

### Examples

**Input:**
```
[4, 3, 2, 6]
```
**Output:**
```
29
```

---

**Input:**
```
[1, 2, 3, 4, 5]
```
**Output:**
```
33
```

---

## 3. Max Number of Non-overlapping Meetings
A problem that teaches interval scheduling optimization and demonstrates meeting room allocation algorithms using greedy approach for efficient time management and resource utilization operations.

Given **start and end times** of meetings, find the **maximum number of non-overlapping meetings** that can be held in a **single room** using optimal scheduling strategy. This operation is fundamental in **meeting scheduling** and **resource optimization** where you need to **maximize meeting participation** within time and space constraints efficiently. The technique uses **earliest finish time greedy approach** to select meetings that end first, as this leaves maximum time availability for subsequent meetings in the same room. This concept is essential in **conference management**, **resource booking**, and **calendar optimization** where maximizing utilization while avoiding conflicts enables efficient scheduling and optimal facility management in shared-resource environments.

This teaches **interval scheduling algorithms** and **meeting optimization techniques** that are crucial for **resource allocation and efficient time management operations**.

**Your task:** Implement greedy meeting scheduling using earliest finish time selection to maximize non-overlapping meeting participation in single-room constraint.

### Examples

**Input:**
```
start = [1, 3, 0, 5, 8, 5], end = [2, 4, 6, 7, 9, 9]
```
**Output:**
```
4
```
