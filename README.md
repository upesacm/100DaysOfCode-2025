<h2 align="center">Day 86 (09/09/2025)</h2>

## 1. Detect Cycle in Undirected Graph
A problem that demonstrates cycle detection techniques and teaches undirected graph analysis algorithms using Union-Find or DFS-based detection for efficient graph cycle identification and connectivity validation operations.

Given an **undirected graph with vertices and edges**, check if the graph **contains a cycle** using cycle detection strategy. This operation is fundamental in **graph validation** and **structural analysis** where you need to **identify circular dependencies** for integrity checking efficiently. The technique uses **DFS with parent tracking** or **Union-Find data structure** to detect back edges that create cycles, ensuring complete graph coverage while avoiding false positives from tree edges. This concept is essential in **network topology validation**, **dependency checking**, and **circuit analysis** where identifying cycles enables structural integrity verification and optimal loop detection in undirected graph-based systems.

This demonstrates **cycle detection algorithms** and **graph validation techniques** that are crucial for **structural analysis and efficient circular dependency identification operations**.

**Your task:** Implement DFS-based or Union-Find cycle detection using parent tracking to identify circular paths in undirected graph structures.

### Examples

**Input:**
```
Vertices = 3
Edges = [[0,1],[1,2],[2,0]]
Graph:
0 - 1
|   |
2 - 2
```
**Output:**
```
Yes
```

---

**Input:**
```
Vertices = 3
Edges = [[0,1],[1,2]]
Graph:
0 - 1 - 2
```
**Output:**
```
No
```

---

## 2. Detect Cycle in Directed Graph
A problem that introduces directed cycle analysis and teaches DFS-based detection algorithms using color-coding or recursion stack for efficient directed graph cycle identification and topological validation operations.

Given a **directed graph with vertices and edges**, check if the graph **contains a cycle** using directed cycle detection strategy. This operation is fundamental in **dependency analysis** and **topological validation** where you need to **identify circular dependencies** in directed relationships efficiently. The technique uses **DFS with recursion stack tracking** or **three-color approach** (white-gray-black) to detect back edges in directed graphs, distinguishing between tree edges and actual cycles. This concept is essential in **task scheduling**, **dependency resolution**, and **deadlock detection** where identifying directed cycles enables dependency validation and optimal circular reference detection in directed graph-based workflow systems.

This introduces **directed cycle detection algorithms** and **dependency validation techniques** that are essential for **topological analysis and efficient circular dependency identification operations**.

**Your task:** Implement DFS-based directed cycle detection using recursion stack or color-coding to identify circular dependencies in directed graph structures.

### Examples

**Input:**
```
Vertices = 3
Edges = [[0,1],[1,2],[2,0]]
Graph:
0 → 1
↑   ↓
2 ← 2
```
**Output:**
```
Yes
```

---

**Input:**
```
Vertices = 4
Edges = [[0,1],[1,2],[2,3]]
Graph:
0 → 1 → 2 → 3
```
**Output:**
```
No
```

---

## 3. Topological Sort (DFS)
A problem that teaches dependency ordering and demonstrates DFS-based topological sorting algorithms using finish-time ordering for efficient directed acyclic graph linearization and task scheduling operations.

Given a **directed acyclic graph (DAG)**, produce a **valid topological ordering** of vertices using DFS-based topological sort strategy. This operation is fundamental in **dependency resolution** and **task scheduling** where you need to **order vertices respecting dependencies** for sequential processing efficiently. The technique uses **DFS with finish-time tracking** by performing deep exploration and adding vertices to result in reverse finish order, ensuring all dependencies are satisfied in the final ordering. This concept is essential in **build systems**, **course scheduling**, and **project management** where ordering tasks based on dependencies enables sequential execution and optimal dependency-respecting workflow management in DAG-structured systems.

This teaches **topological sorting algorithms** and **dependency ordering techniques** that are crucial for **task scheduling and efficient dependency-based linearization operations**.

**Your task:** Implement DFS-based topological sorting using finish-time ordering to produce valid dependency-respecting sequence from directed acyclic graph.

### Examples

**Input:**
```
Vertices = 4
Edges = [[0,1],[0,2],[1,3],[2,3]]
Graph:
0 → 1
↓   ↓
2 → 3
```
**Output:**
```
0 1 2 3 (or 0 2 1 3)
```

---

**Input:**
```
Vertices = 6
Edges = [[5,2],[5,0],[4,0],[4,1],[2,3],[3,1]]
Graph:
5 → 2 → 3
↓       ↓
0       1
↑       ↑
4 ──────┘
```
**Output:**
```
4 5 0 2 3 1 (one valid order)
```
