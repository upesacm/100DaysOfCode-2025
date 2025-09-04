<h2 align="center">Day 80 (03/09/2025)</h2>

## 1. Lowest Common Ancestor (LCA)
A problem that demonstrates ancestral relationship analysis and teaches BST property-based ancestor finding algorithms using efficient navigation for optimal common parent identification and hierarchical relationship discovery operations.

Given a **BST and two nodes**, find their **Lowest Common Ancestor** using BST property-based navigation strategy. This operation is fundamental in **hierarchical analysis** and **relationship discovery** where you need to **identify common ancestors** efficiently in ordered tree structures. The technique uses **BST property navigation** by comparing node values with current node: if both nodes are smaller, go left; if both larger, go right; otherwise current node is LCA. This concept is essential in **genealogy systems**, **organizational hierarchies**, and **version control** where finding common ancestors enables relationship analysis and optimal merge point identification in tree-structured lineage systems.

This demonstrates **LCA algorithms** and **BST navigation techniques** that are crucial for **ancestral analysis and efficient common parent discovery operations**.

**Your task:** Implement BST property-based LCA finding using value comparison navigation to efficiently locate lowest common ancestor with optimal tree traversal.

### Examples

**Input:**
```
Tree:
      6
    /   \
   2     8
  / \   / \
 0   4 7   9
Nodes = 2, 8
```
**Output:**
```
6
```

---

**Input:**
```
Tree:
      6
    /   \
   2     8
  / \   / \
 0   4 7   9
Nodes = 2, 4
```
**Output:**
```
2
```

---

## 2. Delete Node in BST
A problem that introduces dynamic BST maintenance and teaches node removal algorithms using successor/predecessor replacement for efficient binary search tree modification while preserving ordering properties.

Given a **BST and target node**, delete the node while **maintaining BST properties** using case-based removal strategy. This operation is fundamental in **dynamic data management** and **structure maintenance** where you need to **remove elements efficiently** while preserving sorted order. The technique uses **case-based deletion**: leaf nodes removed directly, single-child nodes replaced by child, two-child nodes replaced by inorder successor (or predecessor) to maintain BST ordering. This concept is essential in **database operations**, **dynamic indexing**, and **cache management** where removing elements while maintaining structure enables efficient data management and optimal tree integrity in evolving BST systems.

This introduces **BST deletion algorithms** and **structure maintenance techniques** that are essential for **dynamic tree modification and efficient node removal operations**.

**Your task:** Implement BST node deletion using case-based removal with successor replacement to maintain optimal BST properties after modification.

### Examples

**Input:**
```
Tree:
    5
   / \
  3   6
 / \
2   4
Delete: 3
```
**Output:**
```
2 4 5 6
```

---

**Input:**
```
Tree:
   10
  /  \
 5   15
Delete: 10
```
**Output:**
```
5 15
```

---

## 3. Kth Smallest in BST
A problem that teaches order statistic queries and demonstrates inorder traversal optimization algorithms using counting approach for efficient BST rank-based element retrieval and position-based access operations.

Given a **BST and integer K**, find the **Kth smallest element** using inorder traversal with counting strategy. This operation is fundamental in **order statistics** and **rank-based queries** where you need to **access elements by position** in sorted order efficiently. The technique uses **inorder traversal with counter** by traversing left-root-right while maintaining count, returning element when count reaches K, leveraging BST's natural sorting property. This concept is essential in **ranking systems**, **percentile calculations**, and **statistical analysis** where accessing elements by rank enables efficient order-based queries and optimal position-specific retrieval in sorted tree structures.

This teaches **order statistic algorithms** and **rank-based access techniques** that are crucial for **position-based queries and efficient Kth element retrieval operations**.

**Your task:** Implement inorder traversal with counting using position tracking to efficiently locate Kth smallest element in BST sorted order.

### Examples

**Input:**
```
Tree:
  3
 / \
1   4
 \
  2
K = 1
```
**Output:**
```
1
```

---

**Input:**
```
Tree:
    5
   / \
  3   6
 / \
2   4
/
1
K = 3
```
**Output:**
```
3
```
