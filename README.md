<h2 align="center">Day 76 (30/08/2025)</h2>

## 1. Convert to Sum Tree
A problem that demonstrates tree transformation techniques and teaches recursive subtree summation algorithms using post-order modification for efficient binary tree value aggregation and structural data consolidation operations.

Given a **binary tree**, transform it into a **sum tree** where every node contains the **sum of its left and right subtrees**, with **leaf nodes becoming 0** using recursive bottom-up transformation strategy. This operation is fundamental in **tree restructuring** and **value aggregation** where you need to **consolidate subtree information** into parent nodes efficiently. The technique uses **post-order recursive transformation** by first converting subtrees, then updating current node to sum of original subtree values, preserving structural integrity while aggregating data. This concept is essential in **data aggregation systems**, **hierarchical calculations**, and **summary generation** where consolidating child information enables efficient parent-level analysis and optimal aggregated reporting in tree-structured data systems.

This demonstrates **tree transformation algorithms** and **recursive aggregation techniques** that are crucial for **structural modification and efficient value consolidation operations**.

**Your task:** Implement post-order recursive transformation using subtree summation to convert binary tree into sum tree with aggregated parent values.

### Examples

**Input:**
```
      10
     /  \
   -2    6
   /  \ /  \
  8  -4 7  5
```
**Output (sum tree):**
```
      20
     /  \
    4   12
   /  \ /  \
  0  0 0  0
```

---

## 2. Print Ancestors of a Node
A problem that introduces path tracking analysis and teaches recursive ancestor identification algorithms using backtracking approach for efficient binary tree lineage discovery and hierarchical relationship exploration operations.

Given a **binary tree and target node value**, print **all ancestors** of the given node using recursive path tracking strategy. This operation is fundamental in **lineage analysis** and **hierarchical navigation** where you need to **trace parent relationships** up to root efficiently. The technique uses **recursive path finding with backtracking** by searching for target node while maintaining path, then printing all nodes in path when target is found. This concept is essential in **genealogy systems**, **organizational hierarchies**, and **dependency tracking** where identifying ancestor relationships enables lineage analysis and optimal hierarchical understanding in parent-child structured systems.

This introduces **ancestor tracking algorithms** and **path discovery techniques** that are essential for **lineage analysis and efficient hierarchical relationship exploration operations**.

**Your task:** Implement recursive path tracking using backtracking to discover and print all ancestor nodes from target to root in hierarchical order.

### Examples

**Input:**
```
Tree:
    1
   / \
  2   3
 /
4
Node = 4
```
**Output:**
```
2 1
```

---

## 3. Count Nodes at Given Level
A problem that teaches level-specific enumeration and demonstrates depth-based counting algorithms using recursive level tracking for efficient binary tree node quantification and level-wise population analysis operations.

Given a **binary tree and target level**, count the **number of nodes** present at that **specific level** using recursive depth-based counting strategy. This operation is fundamental in **level analysis** and **population assessment** where you need to **quantify nodes at specific depths** for structural understanding efficiently. The technique uses **recursive level tracking** by decrementing target level at each depth until reaching target, then counting nodes at that specific level. This concept is essential in **capacity planning**, **load distribution**, and **structural analysis** where understanding node distribution across levels enables optimal resource allocation and efficient level-based operations in hierarchical tree systems.

This teaches **level-specific counting algorithms** and **depth-based enumeration techniques** that are crucial for **population analysis and efficient level-wise node quantification operations**.

**Your task:** Implement recursive level tracking using depth-based counting to quantify and return total nodes present at specified tree level.

### Examples

**Input:**
```
    1
   / \
  2   3
 /
4
Level = 2
```
**Output:**
```
2 (Nodes 2 and 3)
```
