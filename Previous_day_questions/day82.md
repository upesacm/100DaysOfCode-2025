<h2 align="center">Day 82 (05/09/2025)</h2>

## 1. Balance BST from Sorted Array
A problem that demonstrates optimal tree construction and teaches divide-and-conquer building algorithms using recursive middle-element selection for efficient balanced binary search tree creation and height optimization operations.

Given a **sorted array**, construct a **height-balanced BST** using divide-and-conquer approach. This operation is fundamental in **optimal tree construction** and **performance optimization** where you need to **create balanced structures** for logarithmic operation guarantees efficiently. The technique uses **recursive middle-element selection** by choosing middle element as root and recursively building left and right subtrees from remaining halves, ensuring balanced height distribution. This concept is essential in **database indexing**, **search optimization**, and **data structure initialization** where creating balanced trees enables optimal performance and efficient worst-case operation guarantees in BST-based systems.

This demonstrates **balanced construction algorithms** and **divide-and-conquer techniques** that are crucial for **optimal tree building and efficient height-balanced BST creation operations**.

**Your task:** Implement recursive divide-and-conquer construction using middle-element selection to build optimally balanced BST from sorted input array.

### Examples

**Input:**
```
[1, 2, 3, 4, 5, 6, 7]
```
**Output (Preorder):**
```
4 2 1 3 6 5 7
```
**Resulting Tree:**
```
    4
   / \
  2   6
 / \ / \
1  3 5  7
```

---

**Input:**
```
[10, 20, 30, 40]
```
**Output (Preorder):**
```
20 10 30 40
```
**Resulting Tree:**
```
   20
  /  \
10   30
      \
      40
```

---

## 2. Check if BST is Balanced
A problem that introduces balance validation and teaches height-difference analysis algorithms using recursive balance checking for efficient binary search tree stability assessment and performance guarantee verification operations.

Given a **Binary Search Tree**, check if it is **height-balanced** where **height difference between subtrees is at most 1** using recursive validation strategy. This operation is fundamental in **performance analysis** and **structure validation** where you need to **verify optimal tree properties** for operation efficiency guarantees. The technique uses **recursive height calculation with balance checking** by computing subtree heights and ensuring height difference doesn't exceed 1 at each node while propagating validation upward. This concept is essential in **performance monitoring**, **tree maintenance**, and **optimization verification** where ensuring balance enables predictable performance and optimal operation complexity in BST applications.

This introduces **balance validation algorithms** and **height analysis techniques** that are essential for **stability checking and efficient performance guarantee verification operations**.

**Your task:** Implement recursive balance validation using height-difference analysis to verify BST maintains balanced structure throughout all levels.

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
**Output:**
```
Yes
```

---

**Input:**
```
Tree:
  1
   \
    2
     \
      3
```
**Output:**
```
No
```

---

## 3. Convert BST to Greater Tree
A problem that teaches cumulative transformation and demonstrates reverse inorder modification algorithms using greater-sum accumulation for efficient binary search tree value enhancement and prefix-sum based node updating operations.

Given a **Binary Search Tree**, transform it so each node's value becomes **original value plus sum of all greater nodes** using reverse inorder accumulation strategy. This operation is fundamental in **cumulative calculations** and **value transformation** where you need to **enhance node values** with aggregate information efficiently. The technique uses **reverse inorder traversal (right-root-left)** while maintaining running sum of visited nodes, adding accumulated sum to each node's value as it processes nodes in descending order. This concept is essential in **financial calculations**, **ranking systems**, and **cumulative analysis** where incorporating aggregate information enables enhanced data representation and optimal cumulative value computation in ordered tree structures.

This teaches **cumulative transformation algorithms** and **reverse traversal techniques** that are crucial for **value enhancement and efficient aggregate-based node modification operations**.

**Your task:** Implement reverse inorder transformation using cumulative sum tracking to enhance each node with accumulated greater-value information.

### Examples

**Input:**
```
Tree:
  5
 / \
2  13
```
**Output Inorder:**
```
20 18 13
```
**Resulting Tree:**
```
  18
 /  \
20  13
```

---

**Input:**
```
Tree:
    2
   / \
  0   3
 / \
-4  1
```
**Output Inorder:**
```
2 6 5 3 3
```
**Resulting Tree:**
```
    5
   / \
  6   3
 / \
2   3
```
