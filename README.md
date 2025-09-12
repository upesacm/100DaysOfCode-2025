<h2 align="center">Day 89 (12/09/2025)</h2>

## 1. Kruskal's Algorithm (MST)
A problem that demonstrates edge-based minimum spanning tree construction and teaches union-find optimization algorithms using greedy edge selection for efficient network connectivity and minimal cost tree building operations.

Given a **weighted undirected graph**, find the **minimum spanning tree cost** using edge-sorting strategy. This operation is fundamental in **network design** and **infrastructure optimization** where you need to **connect all vertices with minimum total weight** for cost-effective connectivity efficiently. The technique uses **greedy algorithm with union-find data structure** to sort edges by weight and select minimum cost edges that don't create cycles, ensuring optimal spanning tree construction. This concept is essential in **network routing**, **circuit design**, and **resource optimization** where minimizing connection costs enables efficient infrastructure planning and optimal cost-based connectivity in weighted graph systems.

This demonstrates **greedy algorithms** and **union-find techniques** that are crucial for **minimum spanning tree construction and efficient cost optimization operations**.

**Your task:** Implement Kruskal's algorithm using edge sorting and union-find to construct minimum spanning tree with optimal total weight.

### Examples

**Input:**
```
Graph Structure:
Vertices = 4
Edges with weights:
0---1 (weight: 10)
|   |
|   3 (weight: 15)
|  /|
| / |
2   | (0-2: 6, 0-3: 5, 2-3: 4)
 \ /
  3

Visual representation:
    10
0 ----- 1
|\ 6    |
|  \    | 15
5|   \2  |
 |    \ /|
 3 ---- 2
    4

Selected edges in MST:
2-3 (4) + 0-3 (5) + 0-1 (10) = 19
```
**Output:**
```
19
```

---

**Input:**
```
Graph Structure:
Vertices = 3
Edges with weights:
0 --- 1 (weight: 1)
|     |
|3    |2
|     |
2 ----

Visual representation:
0 --- 1
|  1  |
|3    |2
|     |
2 ----

Selected edges in MST:
0-1 (1) + 1-2 (2) = 3
```
**Output:**
```
3
```

---

## 2. Prim's Algorithm (MST)
A problem that introduces vertex-based minimum spanning tree construction and teaches priority queue optimization algorithms using incremental vertex addition for efficient network growth and minimal weight tree expansion operations.

Given a **weighted undirected graph**, find the **MST cost using vertex-growing strategy**. This operation is fundamental in **network expansion** and **incremental connectivity** where you need to **grow spanning tree vertex by vertex** selecting minimum weight edges efficiently. The technique uses **priority queue with visited tracking** to always select the minimum weight edge connecting tree to remaining vertices, ensuring optimal incremental tree construction. This concept is essential in **network protocols**, **cluster analysis**, and **progressive optimization** where vertex-based growth enables efficient incremental connectivity and optimal weight-based expansion in dynamic graph systems.

This introduces **priority queue algorithms** and **incremental construction techniques** that are essential for **vertex-based MST building and efficient progressive optimization operations**.

**Your task:** Implement Prim's algorithm using priority queue and visited tracking to grow minimum spanning tree incrementally from starting vertex.

### Examples

**Input:**
```
Graph Structure:
Vertices = 5
Edges with weights:

Visual representation:
    2     3
0 ---- 1 ---- 2
|  6  /| 5   /|
|   /8 |   /7 |
|  /   |  /   |
| /    | /    |
3 ---- 4 ----/
   9

Adjacency with weights:
0-1: 2, 0-3: 6
1-2: 3, 1-3: 8, 1-4: 5  
2-4: 7
3-4: 9

Selected edges in MST:
0-1 (2) + 1-2 (3) + 1-4 (5) + 0-3 (6) = 16
```
**Output:**
```
16
```

---

**Input:**
```
Graph Structure:
Vertices = 4
Edges with weights:

Visual representation:
0 --- 1
|  1  |
|2    |3
|     |
2 --- 3
   4

Selected edges in MST:
0-1 (1) + 0-2 (2) + 2-3 (4) = 7
```
**Output:**
```
7
```

---

## 3. Strongly Connected Components (Kosaraju)
A problem that teaches directed graph decomposition and demonstrates two-pass DFS algorithms using transpose graph analysis for efficient component identification and connectivity classification operations.

Given a **directed graph**, find the **number of strongly connected components** using dual-traversal strategy. This operation is fundamental in **graph analysis** and **dependency resolution** where you need to **identify mutually reachable vertex groups** for structural understanding efficiently. The technique uses **Kosaraju's two-pass algorithm** with first DFS on original graph for finish time ordering, then DFS on transpose graph in reverse finish order to identify SCCs. This concept is essential in **compiler design**, **web link analysis**, and **social network clustering** where identifying strongly connected regions enables efficient structural analysis and optimal component-based processing in directed graph systems.

This teaches **two-pass algorithms** and **graph decomposition techniques** that are crucial for **strongly connected component detection and efficient connectivity analysis operations**.

**Your task:** Implement Kosaraju's algorithm using two DFS passes on original and transpose graphs to identify all strongly connected components.

### Examples

**Input:**
```
Directed Graph Structure:
Vertices = 5
Edges = [[1,0],[0,2],[2,1],[0,3],[3,4]]

Visual representation:
1 ← 0 → 3 → 4
↓ ↗ ↑
→ 2

Strongly Connected Components:
SCC 1: {0, 1, 2} - mutual reachability
SCC 2: {3} - single vertex  
SCC 3: {4} - single vertex

Total SCCs: 3
```
**Output:**
```
3
```

---

**Input:**
```
Directed Graph Structure:
Vertices = 4
Edges = [[0,1],[1,2],[2,3]]

Visual representation:
0 → 1 → 2 → 3

No cycles - each vertex is its own SCC
SCC 1: {0}
SCC 2: {1}  
SCC 3: {2}
SCC 4: {3}

Total SCCs: 4
```
**Output:**
```
4
```
