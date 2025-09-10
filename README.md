<h2 align="center">Day 87 (10/09/2025)</h2>

## 1. Shortest Path in Unweighted Graph
A problem that demonstrates BFS-based distance calculation and teaches level-wise shortest path algorithms using queue-based exploration for efficient unweighted graph distance computation and optimal path finding operations.

Given an **unweighted graph and source vertex**, find the **shortest distance from source to all nodes** using BFS-based shortest path strategy. This operation is fundamental in **distance analysis** and **path optimization** where you need to **calculate minimum hop distances** in equal-weight networks efficiently. The technique uses **BFS with distance tracking** by exploring nodes level by level, assigning distances based on BFS levels, ensuring optimal paths due to BFS's level-wise nature in unweighted graphs. This concept is essential in **social networks**, **network routing**, and **game pathfinding** where finding shortest paths enables optimal navigation and efficient distance-based analysis in uniform-cost graph structures.

This demonstrates **BFS pathfinding algorithms** and **distance computation techniques** that are crucial for **shortest path analysis and efficient unweighted graph navigation operations**.

**Your task:** Implement BFS-based shortest path calculation using level-wise exploration to compute minimum distances from source to all reachable vertices.

### Examples

**Input:**
```
Vertices = 6
Edges = [[0,1],[0,2],[1,3],[2,4],[4,5]]
Source = 0
Graph:
  0
 / \
1   2
|   |
3   4
    |
    5
```
**Output:**
```
Distances = [0,1,1,2,2,3]
```

---

**Input:**
```
Vertices = 4
Edges = [[0,1],[1,2],[2,3]]
Source = 0
Graph:
0 - 1 - 2 - 3
```
**Output:**
```
[0,1,2,3]
```

---

## 2. Dijkstra's Algorithm (Shortest Path in Weighted Graph)
A problem that introduces weighted graph pathfinding and teaches greedy shortest path algorithms using priority queue optimization for efficient weighted graph distance computation and optimal route discovery operations.

Given a **weighted graph with non-negative weights and source vertex**, find the **shortest distance from source to all vertices** using Dijkstra's greedy shortest path strategy. This operation is fundamental in **weighted pathfinding** and **route optimization** where you need to **minimize total path costs** in weighted networks efficiently. The technique uses **priority queue with greedy selection** by always processing the vertex with minimum known distance, relaxing adjacent edges to find shorter paths, ensuring optimality through greedy choice property. This concept is essential in **GPS navigation**, **network routing protocols**, and **logistics optimization** where finding minimum-cost paths enables efficient routing and optimal cost-based navigation in weighted graph transportation systems.

This introduces **Dijkstra's algorithm** and **greedy pathfinding techniques** that are essential for **weighted graph optimization and efficient minimum-cost path discovery operations**.

**Your task:** Implement Dijkstra's algorithm using priority queue optimization to compute shortest weighted distances from source to all vertices in non-negative weighted graph.

### Examples

**Input:**
```
Vertices = 5
Edges = [[0,1,2],[0,2,4],[1,2,1],[2,3,7],[1,4,3]]
Source = 0
Weighted Graph:
  0 -(2)- 1
  |(4)   |(1)|(3)
  2 -(7)- 3   4
```
**Output:**
```
[0,2,3,10,5]
```

---

**Input:**
```
Vertices = 3
Edges = [[0,1,5],[1,2,2]]
Source = 0
Graph:
0 -(5)- 1 -(2)- 2
```
**Output:**
```
[0,5,7]
```

---

## 3. Bellman-Ford Algorithm
A problem that teaches negative weight handling and demonstrates relaxation-based shortest path algorithms using iterative edge processing for efficient weighted graph distance computation with negative cycle detection operations.

Given a **weighted graph with possible negative weights and source vertex**, find the **shortest distance from source to all vertices** using Bellman-Ford relaxation-based strategy. This operation is fundamental in **negative weight pathfinding** and **cycle detection** where you need to **handle negative edge weights** while detecting negative cycles efficiently. The technique uses **iterative edge relaxation** by processing all edges V-1 times to find shortest paths, then checking for negative cycles in the Vth iteration, ensuring correctness even with negative weights. This concept is essential in **financial modeling**, **arbitrage detection**, and **constraint systems** where handling negative weights enables optimal pathfinding and efficient negative cycle identification in signed-weight graph applications.

This teaches **Bellman-Ford algorithm** and **negative weight handling techniques** that are crucial for **signed graph optimization and efficient negative cycle detection operations**.

**Your task:** Implement Bellman-Ford algorithm using iterative edge relaxation to compute shortest distances while detecting negative cycles in weighted graphs.

### Examples

**Input:**
```
Vertices = 5
Edges = [[0,1,-1],[0,2,4],[1,2,3],[1,3,2],[1,4,2],[3,2,5],[3,1,1],[4,3,-3]]
Source = 0
Graph with negative weights:
   0
  /|\
(-1) 4
 /   |
1 -(2)-> 4
|\      /(-3)
| (2)  /
|   \ /
(3)  3
|   /|\
2<-5  1
```
**Output:**
```
[0,-1,2,-2,1]
```

---

**Input:**
```
Vertices = 3
Edges = [[0,1,5],[1,2,-2]]
Source = 0
Graph:
0 -(5)- 1 -(-2)- 2
```
**Output:**
```
[0,5,3]
```
