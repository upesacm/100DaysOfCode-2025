<h2 align="center">Day 79 (02/09/2025)</h2>

## 1. Inorder Traversal of BST
A problem that demonstrates BST ordering property and teaches sorted sequence generation algorithms using inorder traversal for efficient binary search tree data extraction and natural ordering verification operations.

Given a **Binary Search Tree**, print elements in **sorted order** using inorder traversal strategy. This operation is fundamental in **sorted data extraction** and **ordering verification** where you need to **retrieve elements in ascending sequence** from BST structures efficiently. The technique uses **inorder traversal (left-root-right)** which naturally produces sorted output for BST due to ordering property, making it optimal for generating sorted sequences without additional sorting. This concept is essential in **sorted reporting**, **range queries**, and **data validation** where extracting ordered sequences enables efficient analysis and optimal sorted data processing in binary search tree applications.

This demonstrates **BST traversal algorithms** and **sorted extraction techniques** that are crucial for **ordered data retrieval and efficient sorting verification operations**.

**Your task:** Implement inorder traversal using left-root-right navigation to extract BST elements in naturally sorted ascending order sequence.

### Examples

**Input:**
```
Tree:
    5
   / \
  3   7
 / \
2   4
```
**Output:**
```
2 3 4 5 7
```

---

**Input:**
```
Tree:
   10
  /  \
 8   12
```
**Output:**
```
8 10 12
```

---

## 2. Count Nodes in BST
A problem that introduces BST size measurement and teaches recursive counting algorithms using complete tree traversal for efficient binary search tree node enumeration and structure analysis operations.

Given a **Binary Search Tree**, find the **total number of nodes** using recursive counting strategy. This operation is fundamental in **tree size analysis** and **capacity measurement** where you need to **quantify BST structure** for memory and performance assessment efficiently. The technique uses **recursive node counting** by adding one for current node plus counts from left and right subtrees, ensuring complete tree traversal for accurate enumeration regardless of BST ordering. This concept is essential in **memory management**, **performance optimization**, and **capacity planning** where understanding tree size enables efficient resource allocation and optimal algorithm selection in BST-based data systems.

This introduces **BST counting algorithms** and **size measurement techniques** that are essential for **structure analysis and efficient node enumeration operations**.

**Your task:** Implement recursive node counting using complete tree traversal to determine total BST size with accurate structure measurement.

### Examples

**Input:**
```
Tree:
  5
 / \
3   7
```
**Output:**
```
3
```

---

**Input:**
```
Tree:
    8
   / \
  6  10
 /
4
```
**Output:**
```
4
```

---

## 3. Check if Valid BST
A problem that teaches BST property validation and demonstrates range-based verification algorithms using recursive boundary checking for efficient binary search tree structure validation and ordering constraint verification operations.

Given a **binary tree**, verify if it is a **valid Binary Search Tree** using range-based validation strategy. This operation is fundamental in **structure validation** and **property verification** where you need to **ensure BST ordering constraints** are satisfied throughout the tree efficiently. The technique uses **recursive range validation** by maintaining min-max bounds for each node, ensuring left subtree values are less than current node and right subtree values are greater, propagating constraints down the tree. This concept is essential in **data integrity checking**, **tree validation**, and **correctness verification** where ensuring BST properties enables reliable operations and optimal structure maintenance in binary search tree systems.

This teaches **BST validation algorithms** and **property verification techniques** that are crucial for **structure validation and efficient ordering constraint checking operations**.

**Your task:** Implement recursive range validation using boundary checking to verify complete BST property satisfaction throughout tree structure.

### Examples

**Input:**
```
Tree:
  2
 / \
1   3
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
  1   4
     / \
    3   6
```
**Output:**
```
No
```
