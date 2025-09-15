<h2 align="center">Day 88 (11/09/2025)</h2>

## 1. Flood Fill (Graph BFS/DFS on Grid)
A problem that demonstrates grid-based graph traversal and teaches pixel replacement algorithms using connected component exploration for efficient image processing and region filling operations.

Given a **2D image grid and starting pixel coordinates**, perform **flood fill operation** to replace connected pixels of same color using traversal-based region detection strategy. This operation is fundamental in **image processing** and **graphics applications** where you need to **fill connected regions with new color** for editing and visual effects efficiently. The technique uses **DFS or BFS traversal** to explore all connected pixels of same color, replacing them with new color while maintaining boundary detection. This concept is essential in **paint bucket tools**, **image segmentation**, and **region analysis** where filling connected areas enables efficient color replacement and optimal region-based processing in grid-based graphics applications.

This demonstrates **grid traversal algorithms** and **connected component techniques** that are crucial for **region filling and efficient pixel-based processing operations**.

**Your task:** Implement flood fill using DFS or BFS traversal to replace connected pixels of same color with new color starting from given coordinates.

### Examples

**Input:**
```
Image = [[1,1,1],[1,1,0],[1,0,1]]
Start = (1,1)
NewColor = 2
```
**Output:**
```
[[2,2,2],[2,2,0],[2,0,1]]
```

---

**Input:**
```
Image = [[0,0,0],[0,0,0]]
Start = (0,0)
NewColor = 1
```
**Output:**
```
[[1,1,1],[1,1,1]]
```

---

## 2. Number of Islands
A problem that introduces connected component counting and teaches grid-based clustering algorithms using DFS exploration for efficient land mass detection and spatial grouping operations.

Given a **2D binary grid representing land and water**, count the **number of distinct islands** using connected component analysis strategy. This operation is fundamental in **geographical analysis** and **clustering problems** where you need to **identify separate connected regions** of land for mapping and spatial analysis efficiently. The technique uses **DFS traversal** to explore each unvisited land cell and mark all connected land cells as visited, counting each complete traversal as one island. This concept is essential in **geographical mapping**, **cluster detection**, and **pattern recognition** where identifying distinct regions enables efficient spatial organization and optimal connected component analysis in grid-based geographical systems.

This introduces **connected component algorithms** and **grid clustering techniques** that are essential for **region counting and efficient spatial grouping operations**.

**Your task:** Implement DFS-based island counting to identify and count all distinct connected land regions in the binary grid.

### Examples

**Input:**
```
Grid = [[1,1,0,0],[1,0,0,1],[0,0,1,1]]
```
**Output:**
```
3
```

---

**Input:**
```
Grid = [[1,1,0],[0,1,0],[0,0,1]]
```
**Output:**
```
2
```

---

## 3. Bipartite Graph Check
A problem that teaches graph coloring concepts and demonstrates two-coloring validation algorithms using BFS/DFS traversal for efficient bipartition detection and graph classification operations.

Given a **graph with vertices and edges**, determine if the graph is **bipartite** (can be colored with two colors) using alternating coloring strategy. This operation is fundamental in **graph theory** and **matching problems** where you need to **verify if vertices can be split into two sets** with no edges within each set efficiently. The technique uses **BFS or DFS with coloring** to assign alternating colors to adjacent vertices, checking for conflicts that would indicate odd cycles. This concept is essential in **matching algorithms**, **scheduling problems**, and **conflict resolution** where bipartite structure enables efficient pairing and optimal resource allocation in graph-based optimization systems.

This teaches **graph coloring algorithms** and **bipartition detection techniques** that are crucial for **two-coloring validation and efficient graph classification operations**.

**Your task:** Implement BFS or DFS-based two-coloring to check if the graph can be properly colored with two colors without adjacent vertices sharing same color.

### Examples

**Input:**
```
Graph Structure:
Vertices = 4
Edges = [[0,1],[1,2],[2,3],[3,0]]

Visual representation:
0 --- 1
|     |
|     |
3 --- 2

Bipartite coloring possible:
Set A: {0, 2} (Color 1)
Set B: {1, 3} (Color 2)
```
**Output:**
```
Yes
```

---

**Input:**
```
Graph Structure:
Vertices = 3
Edges = [[0,1],[1,2],[2,0]]

Visual representation:
  0
 / \
1---2

Triangle graph - odd cycle detected
No valid 2-coloring possible
```
**Output:**
```
No
```
