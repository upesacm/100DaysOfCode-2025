<h2 align="center">Day 78 (01/09/2025)</h2>

## 1. Search in BST
A problem that demonstrates efficient search optimization and teaches BST property utilization algorithms using binary search approach for logarithmic time complexity and optimal data retrieval operations.

Given a **Binary Search Tree and a key**, check if the **key exists** in the tree using BST property-based search strategy. This operation is fundamental in **ordered data retrieval** and **efficient searching** where you need to **locate elements quickly** in sorted hierarchical structures. The technique uses **BST binary search approach** by comparing key with current node and navigating left for smaller values or right for larger values, leveraging the ordered property for logarithmic search complexity. This concept is essential in **database indexing**, **symbol tables**, and **sorted collections** where fast lookups enable efficient data access and optimal query performance in ordered tree-based storage systems.

This demonstrates **BST search algorithms** and **binary search techniques** that are crucial for **efficient data retrieval and optimal logarithmic lookup operations**.

**Your task:** Implement BST search using binary search approach with BST property navigation to efficiently locate target key with optimal time complexity.

### Examples

**Input:**
```
Tree:
    5
   / \
  3   7
 / \ / \
2  4 6  8
Key = 4
```
**Output:**
```
Yes
```

---

**Input:**
```
Tree:
  5
 / \
3   7
Key = 10
```
**Output:**
```
No
```

---

## 2. Insert into BST
A problem that introduces dynamic tree construction and teaches ordered insertion algorithms using BST maintenance approach for efficient data addition while preserving sorted structure and optimal tree organization operations.

Given a **Binary Search Tree and new value**, insert the value while **maintaining BST properties** using recursive ordered insertion strategy. This operation is fundamental in **dynamic data structures** and **ordered collection management** where you need to **add elements efficiently** while preserving sorted order. The technique uses **BST property-based insertion** by comparing new value with nodes and recursively navigating to appropriate subtree, creating new leaf node at correct position to maintain ordering. This concept is essential in **dynamic databases**, **real-time indexing**, and **growing collections** where maintaining sorted order during insertions enables efficient subsequent operations and optimal data organization in evolving tree structures.

This introduces **BST insertion algorithms** and **ordered maintenance techniques** that are essential for **dynamic tree construction and efficient sorted data addition operations**.

**Your task:** Implement BST insertion using recursive navigation with BST property preservation to add new values while maintaining optimal sorted structure.

### Examples

**Input:**
```
Tree:
  5
 / \
3   7
Insert: 4
```
**Output Tree (inorder):**
```
3 4 5 7
```

---

**Input:**
```
Tree:
  10
Insert: 20
```
**Output Tree (inorder):**
```
10 20
```

---

## 3. Minimum & Maximum in BST
A problem that teaches extremum identification and demonstrates BST boundary access algorithms using leftmost/rightmost navigation for efficient minimum and maximum value discovery operations.

Given a **Binary Search Tree**, find the **minimum and maximum elements** using BST property-based boundary navigation strategy. This operation is fundamental in **range analysis** and **boundary identification** where you need to **locate extreme values** efficiently in sorted structures. The technique uses **leftmost/rightmost traversal** by following left pointers for minimum (smallest) value and right pointers for maximum (largest) value, leveraging BST ordering for direct access to extremes. This concept is essential in **statistical analysis**, **range queries**, and **optimization problems** where identifying bounds enables efficient range operations and optimal threshold determination in ordered tree-based data systems.

This teaches **extremum identification algorithms** and **BST boundary techniques** that are crucial for **range analysis and efficient minimum-maximum discovery operations**.

**Your task:** Implement BST extremum finding using leftmost/rightmost navigation to efficiently locate minimum and maximum values with optimal tree traversal.

### Examples

**Input:**
```
Tree:
    8
   / \
  3  10
 / \   \
1   6  14
```
**Output:**
```
Min = 1, Max = 14
```

---

**Input:**
```
Tree:
  5
```
**Output:**
```
Min = 5, Max = 5
```
