<h2 align="center">Day 81 (04/09/2025)</h2>

## 1. Range Sum of BST
A problem that demonstrates range-based aggregation and teaches pruned traversal algorithms using BST property optimization for efficient binary search tree range query processing and selective summation operations.

Given a **BST and range [L, R]**, find the **sum of all values within the range** using optimized traversal strategy. This operation is fundamental in **range analytics** and **selective aggregation** where you need to **compute totals for specific value ranges** efficiently without processing irrelevant nodes. The technique uses **pruned BST traversal** by leveraging ordering property to skip entire subtrees: if current value is less than L, skip left subtree; if greater than R, skip right subtree; otherwise include value and explore both sides. This concept is essential in **financial reporting**, **statistical analysis**, and **database queries** where range-based calculations enable efficient filtered aggregation and optimal selective processing in ordered tree structures.

This demonstrates **range query algorithms** and **pruned traversal techniques** that are crucial for **selective aggregation and efficient range-based summation operations**.

**Your task:** Implement pruned BST traversal using range optimization to efficiently calculate sum of values within specified bounds with minimal node visits.

### Examples

**Input:**
```
Tree:
     10
    /  \
   5   15
  / \    \
 3   7   18
L=7, R=15
```
**Output:**
```
32
```

---

**Input:**
```
Tree:
     10
    /  \
   5   15
  / \ /  \
 3  7 13 18
L=6, R=10
```
**Output:**
```
17
```

---

## 2. BST to Sorted Linked List
A problem that introduces structure conversion techniques and teaches inorder flattening algorithms using BST to linear transformation for efficient binary search tree linearization and sequential data structure creation operations.

Given a **Binary Search Tree**, convert it into a **sorted linked list** using inorder traversal-based flattening strategy. This operation is fundamental in **structure transformation** and **data format conversion** where you need to **linearize hierarchical data** while preserving sorted order efficiently. The technique uses **inorder traversal with linking** by processing nodes in left-root-right order and connecting them sequentially to form sorted linked list, leveraging BST's natural ordering for optimal conversion. This concept is essential in **data serialization**, **format migration**, and **sequential processing** where converting tree structures enables linear access and optimal sequential operations in flattened data representations.

This introduces **structure conversion algorithms** and **tree flattening techniques** that are essential for **linearization and efficient sequential data transformation operations**.

**Your task:** Implement inorder-based BST flattening using sequential linking to convert hierarchical structure into sorted linear linked list representation.

### Examples

**Input:**
```
Tree:
    4
   / \
  2   6
 / \ / \
1  3 5  7
```
**Output List:**
```
1 → 2 → 3 → 4 → 5 → 6 → 7
```

---

**Input:**
```
Tree:
  2
 / \
1   3
```
**Output List:**
```
1 → 2 → 3
```

---

## 3. Print Nodes in Range
A problem that teaches range-based filtering and demonstrates selective traversal algorithms using BST property pruning for efficient binary search tree range query processing and bounded element extraction operations.

Given a **BST and range [L, R]**, print all nodes whose **values fall within the range** using optimized range traversal strategy. This operation is fundamental in **filtered data retrieval** and **range-based queries** where you need to **extract elements within specific bounds** efficiently without examining irrelevant nodes. The technique uses **pruned inorder traversal** by leveraging BST ordering to skip subtrees outside range: traverse left only if current > L, traverse right only if current < R, print current if within bounds. This concept is essential in **search filtering**, **report generation**, and **data extraction** where range-based selection enables efficient bounded queries and optimal filtered retrieval in ordered tree systems.

This teaches **range filtering algorithms** and **selective traversal techniques** that are crucial for **bounded extraction and efficient range-based query processing operations**.

**Your task:** Implement pruned range traversal using BST property optimization to efficiently extract and print all nodes within specified value bounds.

### Examples

**Input:**
```
Tree:
     10
    /  \
   5   15
  / \    \
 3   7   18
L=7, R=15
```
**Output:**
```
7 10 15
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
L=2, R=8
```
**Output:**
```
2 4 6 7 8
```
