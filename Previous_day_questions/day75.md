<h2 align="center">Day 75 (29/08/2025)</h2>

## 1. Left View of Binary Tree
A problem that demonstrates perspective-based tree traversal and teaches leftmost node identification algorithms using level-order processing for efficient binary tree boundary visualization and side-specific data access operations.

Given a **binary tree**, print the **leftmost node at each level** using level-wise boundary identification strategy. This operation is fundamental in **tree visualization** and **boundary analysis** where you need to **identify visible nodes from specific perspectives** for display optimization efficiently. The technique uses **level-order traversal with first-node tracking** by processing nodes level by level and capturing the first (leftmost) node encountered at each depth. This concept is essential in **UI rendering**, **tree visualization**, and **profile analysis** where displaying boundary elements enables clear visual representation and optimal perspective-based presentation in hierarchical display systems.

This demonstrates **perspective-based traversal algorithms** and **boundary identification techniques** that are crucial for **tree visualization and efficient side-specific node access operations**.

**Your task:** Implement level-order traversal with leftmost tracking to identify and print the first visible node from left perspective at each tree level.

### Examples

**Input:**
```
    1
   / \
  2   3
   \
    4
```
**Output:**
```
1 2 4
```

---

## 2. Right View of Binary Tree
A problem that introduces right-perspective analysis and teaches rightmost node selection algorithms using level-based boundary detection for efficient binary tree right-side visualization and perspective-specific data extraction operations.

Given a **binary tree**, print the **rightmost node at each level** using right-boundary identification approach. This operation is fundamental in **perspective visualization** and **right-side analysis** where you need to **capture visible elements from right viewpoint** for comprehensive display representation efficiently. The technique uses **level-order traversal with last-node tracking** by processing all nodes at each level and retaining the rightmost (last) node encountered at each depth. This concept is essential in **architectural visualization**, **profile rendering**, and **boundary detection** where identifying right-edge elements enables complete perspective analysis and optimal right-side representation in structured tree visualization systems.

This introduces **right-perspective algorithms** and **rightmost selection techniques** that are essential for **boundary visualization and efficient right-side node identification operations**.

**Your task:** Implement level-based traversal with rightmost tracking to capture and print the last visible node from right perspective at each tree level.

### Examples

**Input:**
```
    1
   / \
  2   3
 /
4
```
**Output:**
```
1 3 4
```

---

## 3. Diameter of Binary Tree
A problem that teaches tree metric calculation and demonstrates longest path algorithms using recursive height-based analysis for efficient binary tree span measurement and maximum distance determination operations.

Given a **binary tree**, find the **diameter** (length of longest path between any two nodes) using recursive path analysis strategy. This operation is fundamental in **tree metrics** and **span analysis** where you need to **determine maximum connectivity distance** for structural assessment efficiently. The technique uses **recursive height calculation with diameter tracking** by computing left and right subtree heights at each node, calculating potential diameter through current node, and maintaining global maximum. This concept is essential in **network analysis**, **social graphs**, and **communication systems** where measuring maximum distances enables connectivity assessment and optimal path planning in tree-structured networks.

This teaches **tree metric algorithms** and **longest path techniques** that are crucial for **span measurement and efficient maximum distance calculation operations**.

**Your task:** Implement recursive diameter calculation using height-based analysis to determine the longest possible path between any two nodes in binary tree.

### Examples

**Input:**
```
    1
   / \
  2   3
 / \
4   5
```
**Output:**
```
4 (Path: 4 → 2 → 1 → 3)
```
