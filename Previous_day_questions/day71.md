<h2 align="center">Day 71 (25/08/2025)</h2>

## 1. Inorder Traversal of Binary Tree
A problem that demonstrates tree traversal fundamentals and teaches recursive navigation algorithms using left-root-right ordering for efficient binary tree exploration and data extraction operations.

Given a **binary tree**, print its **inorder traversal** using recursive left-root-right navigation strategy. This operation is fundamental in **tree traversal** and **data structure navigation** where you need to **visit nodes systematically** in sorted order for binary search trees efficiently. The technique uses **recursive inorder approach** visiting left subtree first, then current node, finally right subtree, which naturally produces sorted sequence for BST structures. This concept is essential in **expression evaluation**, **syntax parsing**, and **data retrieval** where systematic node visitation enables ordered processing and structured data access in hierarchical tree-based systems.

This demonstrates **tree traversal algorithms** and **recursive navigation techniques** that are crucial for **binary tree exploration and efficient data extraction operations**.

**Your task:** Implement recursive inorder traversal using left-root-right visitation pattern to systematically explore binary tree nodes in proper sequence.

### Examples

**Input:**
```
    1
     \
      3
     /
    2
```
**Output:**
```
1 3 2
```

---

**Input:**
```
    4
   / \
  2   5
```
**Output:**
```
2 4 5
```

---

## 2. Count Leaf Nodes
A problem that introduces node classification analysis and teaches leaf identification algorithms using recursive counting approach for efficient tree structure analysis and terminal node detection operations.

Given a **binary tree**, count the **number of leaf nodes** (nodes with no children) using recursive structural analysis strategy. This operation is fundamental in **tree analysis** and **node classification** where you need to **identify terminal elements** for structural understanding efficiently. The technique uses **recursive leaf detection** by checking if a node has no left or right children, then recursively counting leaves in subtrees for complete tree analysis. This concept is essential in **decision trees**, **file systems**, and **organizational structures** where identifying endpoints enables structural analysis and optimal resource allocation in hierarchical systems.

This introduces **node classification algorithms** and **structural analysis techniques** that are essential for **tree examination and efficient leaf detection operations**.

**Your task:** Implement recursive leaf counting using null-child validation to identify and count terminal nodes throughout the binary tree structure.

### Examples

**Input:**
```
    1
   / \
  2   3
```
**Output:**
```
2
```

---

**Input:**
```
   10
    \
    20
   /
  15
```
**Output:**
```
1
```

---

## 3. Height of Binary Tree
A problem that teaches tree depth measurement and demonstrates recursive height calculation algorithms using maximum subtree depth for efficient tree structure analysis and depth determination operations.

Given a **binary tree**, find its **height** (maximum depth from root to any leaf) using recursive depth calculation approach. This operation is fundamental in **tree analysis** and **structural measurement** where you need to **determine maximum path length** for performance and balance assessment efficiently. The technique uses **recursive maximum depth calculation** by finding heights of left and right subtrees, then taking maximum plus one for current level. This concept is essential in **balanced trees**, **performance optimization**, and **memory management** where understanding tree depth enables efficient algorithms and optimal data structure selection in depth-sensitive applications.

This teaches **depth calculation algorithms** and **recursive measurement techniques** that are crucial for **tree analysis and efficient height determination operations**.

**Your task:** Implement recursive height calculation using maximum subtree depth comparison to determine the longest path from root to any leaf node.

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
3
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
2
```
