<h2 align="center">Day 85 (08/09/2025)</h2>

## 1. BFS Traversal of Graph
A problem that demonstrates breadth-first exploration and teaches level-wise graph traversal algorithms using queue-based systematic navigation for efficient graph node visitation and shortest-path foundation operations.

Given a **graph with vertices and edges**, perform **Breadth-First Search** starting from node 0 using queue-based level-order exploration strategy. This operation is fundamental in **graph exploration** and **systematic traversal** where you need to **visit nodes level by level** for comprehensive graph analysis efficiently. The technique uses **queue-based BFS** by starting from source node, visiting all immediate neighbors first, then their neighbors, ensuring level-wise exploration pattern. This concept is essential in **shortest path algorithms**, **social network analysis**, and **web crawling** where level-wise exploration enables optimal distance-based processing and efficient breadth-first navigation in connected graph structures.

This demonstrates **BFS algorithms** and **queue-based traversal techniques** that are crucial for **level-wise exploration and efficient breadth-first graph navigation operations**.

**Your task:** Implement queue-based BFS using level-order exploration to systematically visit all reachable nodes in breadth-first manner from starting vertex.

### Examples

**Input:**
```
Vertices = 5
Edges = [[0,1],[0,2],[1,3],[2,4]]
Graph:
  0
 / \
1   2
|   |
3   4
```
**Output:**
```
0 1 2 3 4
```

---

**Input:**
```
Vertices = 4
Edges = [[0,1],[1,2],[2,3]]
Graph:
0 - 1 - 2 - 3
```
**Output:**
```
0 1 2 3
```

---

## 2. DFS Traversal of Graph
A problem that introduces depth-first exploration and teaches recursive graph traversal algorithms using stack-based deep navigation for efficient graph node visitation and path-finding foundation operations.

Given a **graph with vertices and edges**, perform **Depth-First Search** starting from node 0 using recursive deep exploration strategy. This operation is fundamental in **graph exploration** and **path analysis** where you need to **visit nodes by going deep** before backtracking for comprehensive graph traversal efficiently. The technique uses **recursive DFS** or **stack-based approach** by exploring as far as possible along each branch before backtracking, ensuring complete path exploration. This concept is essential in **path finding**, **cycle detection**, and **topological sorting** where depth-first exploration enables complete path analysis and optimal deep navigation in connected graph structures.

This introduces **DFS algorithms** and **recursive traversal techniques** that are essential for **depth-first exploration and efficient deep graph navigation operations**.

**Your task:** Implement recursive DFS using deep exploration to systematically visit all reachable nodes by going as deep as possible before backtracking.

### Examples

**Input:**
```
Vertices = 5
Edges = [[0,1],[0,2],[1,3],[2,4]]
Graph:
  0
 / \
1   2
|   |
3   4
```
**Output:**
```
0 1 3 2 4
```

---

**Input:**
```
Vertices = 4
Edges = [[0,1],[1,2],[2,3]]
Graph:
0 - 1 - 2 - 3
```
**Output:**
```
0 1 2 3
```

---

## 3. Count Connected Components
A problem that teaches graph connectivity analysis and demonstrates component identification algorithms using union-find or traversal-based counting for efficient graph structure analysis and disconnected region detection operations.

Given an **undirected graph**, find the **number of connected components** using component identification strategy. This operation is fundamental in **connectivity analysis** and **graph partitioning** where you need to **identify separate connected regions** for structural understanding efficiently. The technique uses **DFS/BFS from unvisited nodes** or **Union-Find data structure** to group connected vertices and count distinct components, ensuring complete graph coverage. This concept is essential in **network analysis**, **cluster detection**, and **social group identification** where finding connected components enables network segmentation and optimal component-based processing in disconnected graph structures.

This teaches **connectivity algorithms** and **component detection techniques** that are crucial for **graph partitioning and efficient connected region identification operations**.

**Your task:** Implement component counting using traversal-based or union-find approach to identify and count all disconnected regions in undirected graph.

### Examples

**Input:**
```
Vertices = 5
Edges = [[0,1],[1,2],[3,4]]
Graph:
0 - 1 - 2    3 - 4
```
**Output:**
```
2
```

---

**Input:**
```
Vertices = 4
Edges = [[0,1],[2,3]]
Graph:
0 - 1    2 - 3
```
**Output:**
```
2
```
