<h2 align="center">Day 74 (28/08/2025)</h2>

## 1. Print Nodes at K Distance
A problem that demonstrates distance-based tree traversal and teaches level-specific access algorithms using recursive depth tracking for efficient binary tree node selection and targeted data retrieval operations.

Given a **binary tree and distance K**, print all nodes that are **exactly K distance from the root** using recursive level-based traversal strategy. This operation is fundamental in **level-specific access** and **distance-based filtering** where you need to **retrieve nodes at specific depths** for targeted analysis efficiently. The technique uses **recursive depth tracking** by decrementing K at each level until reaching target distance, then collecting nodes at that specific level. This concept is essential in **hierarchical navigation**, **organizational charts**, and **network analysis** where accessing nodes at specific distances enables targeted operations and optimal level-based processing in structured tree systems.

This demonstrates **distance-based traversal algorithms** and **level-specific access techniques** that are crucial for **targeted node selection and efficient depth-based retrieval operations**.

**Your task:** Implement recursive distance tracking using depth-based filtering to collect and print all nodes at exactly K distance from root.

### Examples

**Input:**
```
    1
   / \
  2   3
 / \
4   5
K = 2
```
**Output:**
```
4 5
```

---

## 2. Check if Tree is Balanced
A problem that introduces tree balance validation and teaches height-difference analysis algorithms using recursive balance checking for efficient binary tree stability assessment and structural optimization verification operations.

Given a **binary tree**, check if it is **balanced** where **height difference between left and right subtrees is at most 1** using recursive balance validation strategy. This operation is fundamental in **tree stability analysis** and **performance optimization** where you need to **ensure balanced structure** for optimal operation efficiency. The technique uses **recursive height calculation with balance checking** at each node, verifying that height difference between subtrees doesn't exceed 1 while computing heights bottom-up. This concept is essential in **self-balancing trees**, **database indexing**, and **search optimization** where maintaining balance enables logarithmic operations and optimal query performance in tree-based data structures.

This introduces **balance validation algorithms** and **height-difference analysis techniques** that are essential for **tree stability checking and efficient structural optimization verification operations**.

**Your task:** Implement recursive balance checking using height-difference validation to determine if binary tree maintains balanced structure throughout all levels.

### Examples

**Input:**
```
  1
 /
2
/
3
```
**Output:**
```
No
```

---

**Input:**
```
    1
   / \
  2   3
```
**Output:**
```
Yes
```

---

## 3. Print All Root to Leaf Paths
A problem that teaches path enumeration techniques and demonstrates backtracking algorithms using recursive path tracking for efficient binary tree route discovery and complete path exploration operations.

Given a **binary tree**, print **all paths from root to every leaf** using recursive backtracking path enumeration strategy. This operation is fundamental in **path discovery** and **route enumeration** where you need to **identify all possible traversal routes** for comprehensive analysis efficiently. The technique uses **recursive path building with backtracking** by maintaining current path and extending it at each node, printing complete path when reaching leaves, then backtracking for alternative routes. This concept is essential in **decision trees**, **file system traversal**, and **network routing** where discovering all possible paths enables comprehensive analysis and optimal route selection in hierarchical navigation systems.

This teaches **path enumeration algorithms** and **backtracking techniques** that are crucial for **route discovery and efficient complete path exploration operations**.

**Your task:** Implement recursive backtracking using path building to discover and print all possible routes from root to every leaf node.

### Examples

**Input:**
```
    1
   / \
  2   3
   \
    5
```
**Output:**
```
1->2->5
1->3
```
