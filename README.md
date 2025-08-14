<h2 align="center">Day 60 (14/08/2025)</h2>

## 1. Sort a K-Sorted Array
A problem that demonstrates nearly-sorted array optimization and teaches efficient sorting techniques using min-heap for arrays with bounded disorder, leveraging partial order properties for optimal performance.

Given an array where every element is **at most k positions away** from its **sorted position**, sort it using heap-based optimization. This operation is fundamental in **partially sorted data processing** and **bounded disorder optimization** where you need to **sort nearly-ordered sequences** more efficiently than general sorting algorithms. The technique uses **min-heap of size k+1** to maintain the smallest elements within the valid range, ensuring each position gets its correct element. This concept is essential in **real-time data processing**, **streaming algorithms**, and **external sorting** where data arrives in nearly-sorted order and requires efficient ordering with minimal memory overhead.

This teaches **nearly-sorted optimization algorithms** and **bounded heap sorting techniques** that are essential for **partial order processing and efficient k-sorted array manipulation operations**.

**Your task:** Implement k-sorted array optimization using min-heap of size k+1 to achieve better than O(n log n) sorting performance on nearly-sorted data.

### Examples

**Input:**
```
arr = [6, 5, 3, 2, 8, 10, 9], k = 3
```
**Output:**
```
[2, 3, 5, 6, 8, 9, 10]
```

---

**Input:**
```
arr = [3, 2, 1, 5, 4, 7, 6, 5], k = 3
```
**Output:**
```
[1, 2, 3, 4, 5, 5, 6, 7]
```

---

## 2. Median in a Stream
A problem that introduces dynamic median tracking and teaches dual-heap techniques using balanced max-heap and min-heap structures for efficient running median computation in streaming data.

Given a **stream of integers**, find the **median after each insertion** using dual-heap approach for optimal performance. This operation is fundamental in **streaming statistics** and **real-time analytics** where you need to **maintain median values** dynamically as data arrives continuously. The technique uses **balanced dual-heap structure** with max-heap for smaller half and min-heap for larger half, ensuring O(log n) insertion and O(1) median retrieval. This concept is essential in **financial trading**, **sensor data processing**, and **real-time monitoring** where continuous median calculation enables trend analysis and anomaly detection in streaming datasets.

This introduces **streaming median algorithms** and **dual-heap balancing techniques** that are crucial for **real-time statistics and efficient dynamic median computation operations**.

**Your task:** Implement dual-heap median tracking using balanced max-heap and min-heap structures to maintain running median with optimal time complexity.

### Examples

**Input:**
```
[5, 15, 1, 3]
```
**Output:**
```
5, 10, 5, 4
```

---

**Input:**
```
[1, 2, 3, 4, 5]
```
**Output:**
```
1, 1.5, 2, 2.5, 3
```

---

## 3. Top K Frequent Elements
A problem that teaches frequency analysis optimization and demonstrates heap-based selection algorithms using frequency counting and priority queue techniques for efficient top-k element identification.

Given a list of elements, find the **k most frequent elements** using heap-based frequency analysis. This operation is fundamental in **frequency analysis** and **popularity ranking** where you need to **identify most common elements** efficiently from large datasets. The technique combines **frequency counting** with **min-heap of size k** to maintain the k most frequent elements, or uses max-heap for direct frequency-based selection. This concept is essential in **data mining**, **recommendation systems**, and **trend analysis** where finding popular items enables content ranking and user preference analysis in large-scale applications.

This teaches **frequency-based heap algorithms** and **top-k selection techniques** that are essential for **popularity analysis and efficient frequent element identification operations**.

**Your task:** Implement frequency-based top-k selection using heap structures to efficiently identify most frequent elements with optimal time and space complexity.

### Examples

**Input:**
```
arr = [1, 1, 1, 2, 2, 3], k = 2
```
**Output:**
```
[1, 2]
```

---

**Input:**
```
arr = [4, 1, -1, 2, -1, 2, 3], k = 2
```
**Output:**
```
[-1, 2]
```
