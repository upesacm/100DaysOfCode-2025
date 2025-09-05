<h2 align="center">Day 83 (06/09/2025)</h2>

## 1. Vertical Order Traversal of BST
A problem that demonstrates multi-dimensional tree analysis and teaches column-based grouping algorithms using coordinate mapping for efficient binary search tree vertical organization and spatial data structure processing operations.

Given a **Binary Search Tree**, print nodes **column by column** from left to right using coordinate-based grouping strategy. This operation is fundamental in **spatial tree analysis** and **multi-dimensional organization** where you need to **group nodes by vertical position** for layout and visualization purposes efficiently. The technique uses **coordinate mapping with level-order traversal** by assigning horizontal distance (HD) coordinates to nodes: left child gets HD-1, right child gets HD+1, then grouping nodes by same HD values. This concept is essential in **tree visualization**, **layout algorithms**, and **spatial indexing** where organizing nodes by position enables structured display and optimal coordinate-based processing in geometric tree applications.

This demonstrates **coordinate mapping algorithms** and **spatial grouping techniques** that are crucial for **vertical organization and efficient multi-dimensional tree processing operations**.

**Your task:** Implement coordinate-based vertical traversal using horizontal distance mapping to group and display BST nodes by column position.

### Examples

**Input:**
```
Tree:
    3
   / \
  9  20
    /  \
   15   7
```
**Output:**
```
[[9], [3,15], [20], [7]]
```

---

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
[[4], [2], [1,5,6], [3], [7]]
```

---

## 2. Serialize & Deserialize BST
A problem that introduces data persistence techniques and teaches tree encoding/decoding algorithms using preorder serialization for efficient binary search tree storage and reconstruction operations.

Given a **Binary Search Tree**, design methods to **serialize (encode) and deserialize (decode)** the tree using string representation strategy. This operation is fundamental in **data persistence** and **tree storage** where you need to **convert trees to/from string format** for file storage and network transmission efficiently. The technique uses **preorder traversal for serialization** and **recursive reconstruction for deserialization**, leveraging BST properties to reconstruct structure from preorder sequence without needing null markers. This concept is essential in **data serialization**, **network protocols**, and **backup systems** where converting between tree and string formats enables persistent storage and optimal data transmission in BST-based applications.

This introduces **serialization algorithms** and **tree reconstruction techniques** that are essential for **data persistence and efficient tree encoding/decoding operations**.

**Your task:** Implement preorder-based serialization and BST property-based deserialization to enable efficient tree-to-string conversion and reconstruction.

### Examples

**Input Tree:**
```
  2
 / \
1   3
```
**Serialized:**
```
"2,1,3"
```
**Deserialized Inorder:**
```
1 2 3
```

---

**Input Tree:**
```
  5
 / \
3   7
```
**Serialized:**
```
"5,3,7"
```
**Deserialized Inorder:**
```
3 5 7
```

---

## 3. Two Sum in BST
A problem that teaches target-sum searching and demonstrates BST-optimized pair finding algorithms using inorder traversal with two-pointer technique for efficient binary search tree complement detection operations.

Given a **BST and target sum**, check if there exist **two nodes whose sum equals target** using BST-optimized search strategy. This operation is fundamental in **pair detection** and **complement searching** where you need to **find matching value pairs** efficiently in ordered structures. The technique uses **inorder traversal to create sorted array** then applies **two-pointer technique** to find complementary values, or alternatively uses **BST search for complements** during traversal. This concept is essential in **matching algorithms**, **financial calculations**, and **optimization problems** where finding target sums enables efficient pair identification and optimal complement detection in ordered tree-based data systems.

This teaches **pair detection algorithms** and **BST search optimization techniques** that are crucial for **target-sum finding and efficient complement identification operations**.

**Your task:** Implement BST-optimized two-sum detection using either inorder-based two-pointer approach or complement search strategy for efficient pair finding.

### Examples

**Input:**
```
Tree:
    5
   / \
  3   6
 / \   \
2   4   7
Target = 9
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
  3   6
 / \   \
2   4   7
Target = 28
```
**Output:**
```
No
```
