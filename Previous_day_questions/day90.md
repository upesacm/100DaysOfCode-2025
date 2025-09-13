<h2 align="center">Day 90 (13/09/2025)</h2>

## 1. Hamiltonian Path in Graph
A problem that demonstrates complete path traversal and teaches backtracking exploration algorithms using vertex visitation tracking for efficient all-vertex path detection and exhaustive search operations.

Given an **undirected graph**, determine if there exists a **Hamiltonian path** (visits each vertex exactly once) using backtracking strategy. This operation is fundamental in **route planning** and **scheduling problems** where you need to **visit all locations exactly once** for optimal coverage efficiently. The technique uses **recursive backtracking with visited tracking** to explore all possible paths, checking if any path visits every vertex exactly once without repetition. This concept is essential in **traveling salesman problems**, **circuit design**, and **task scheduling** where complete vertex coverage enables efficient route optimization and optimal sequential processing in graph-based navigation systems.

This demonstrates **backtracking algorithms** and **exhaustive search techniques** that are crucial for **complete path detection and efficient vertex traversal operations**.

**Your task:** Implement backtracking-based Hamiltonian path detection to check if graph contains a path visiting all vertices exactly once.

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

Possible Hamiltonian paths:
0 → 1 → 2 → 3 (visits all vertices once)
0 → 3 → 2 → 1 (visits all vertices once)
1 → 0 → 3 → 2 (visits all vertices once)
And other valid permutations...
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
Edges = [[0,1],[1,2]]

Visual representation:
0 --- 1 --- 2

Hamiltonian path exists:
0 → 1 → 2 (visits all vertices exactly once)
Path length = 3 vertices
```
**Output:**
```
Yes
```

---

## 2. Eulerian Path/Circuit
A problem that introduces edge traversal analysis and teaches degree-based classification algorithms using mathematical conditions for efficient complete edge coverage and path existence determination operations.

Given an **undirected graph**, determine if **Eulerian Path or Circuit exists** using degree analysis strategy. This operation is fundamental in **network traversal** and **routing optimization** where you need to **traverse all edges exactly once** for complete coverage efficiently. The technique uses **vertex degree analysis** where Eulerian Circuit exists if all vertices have even degree, and Eulerian Path exists if exactly two vertices have odd degree. This concept is essential in **mail delivery**, **street cleaning**, and **network inspection** where complete edge traversal enables efficient route planning and optimal coverage-based navigation in graph connectivity systems.

This introduces **degree analysis algorithms** and **mathematical graph theory** that are essential for **edge traversal classification and efficient path existence determination operations**.

**Your task:** Implement degree-based analysis to determine existence of Eulerian Path or Circuit using vertex degree counting and mathematical conditions.

### Examples

**Input:**
```
Graph Structure:
Vertices = 4
Edges = [[0,1],[1,2],[2,0],[0,3]]

Visual representation:
  1
 /|\
0---2
|
3

Degree analysis:
Vertex 0: degree 3 (connected to 1,2,3) - ODD
Vertex 1: degree 2 (connected to 0,2) - EVEN  
Vertex 2: degree 2 (connected to 0,1) - EVEN
Vertex 3: degree 1 (connected to 0) - ODD

Exactly 2 odd-degree vertices → Eulerian Path exists
Path: 3 → 0 → 1 → 2 → 0
```
**Output:**
```
Eulerian Path Exists
```

---

**Input:**
```
Graph Structure:
Vertices = 3
Edges = [[0,1],[1,2],[2,0]]

Visual representation:
0 --- 1
 \   /
  \ /
   2

Degree analysis:
Vertex 0: degree 2 (connected to 1,2) - EVEN
Vertex 1: degree 2 (connected to 0,2) - EVEN
Vertex 2: degree 2 (connected to 0,1) - EVEN

All vertices have even degree → Eulerian Circuit exists
Circuit: 0 → 1 → 2 → 0
```
**Output:**
```
Eulerian Circuit Exists
```

---

## 3. Word Ladder (Shortest Transformation Sequence)
A problem that teaches string transformation optimization and demonstrates BFS shortest path algorithms using character-level graph construction for efficient word sequence finding and lexical distance operations.

Given **begin word, end word, and dictionary**, find the **shortest transformation sequence length** using BFS strategy on word graph. This operation is fundamental in **natural language processing** and **sequence optimization** where you need to **find minimal steps between word states** for efficient transformation efficiently. The technique uses **BFS on implicit word graph** where each word is a vertex and edges exist between words differing by one character, ensuring shortest path discovery. This concept is essential in **spell checkers**, **language games**, and **text processing** where finding optimal transformation sequences enables efficient word manipulation and optimal lexical navigation in string-based search systems.

This teaches **BFS optimization algorithms** and **implicit graph construction techniques** that are crucial for **shortest sequence finding and efficient string transformation operations**.

**Your task:** Implement BFS-based word ladder to find shortest transformation sequence from begin word to end word using single-character changes.

### Examples

**Input:**
```
Transformation Problem:
Begin = "hit"
End = "cog"  
WordList = ["hot","dot","dog","lot","log","cog"]

BFS Transformation Graph:
Level 1: "hit" → "hot" (change i→o)
Level 2: "hot" → "dot", "hot" → "lot" (change h→d, h→l)  
Level 3: "dot" → "dog", "lot" → "log" (change t→g)
Level 4: "dog" → "cog", "log" → "cog" (change d→c, l→c)

Shortest paths:
hit → hot → dot → dog → cog (5 words)
hit → hot → lot → log → cog (5 words)

Transformation sequence length: 5
```
**Output:**
```
5
```

---

**Input:**
```
Transformation Problem:
Begin = "hit"
End = "cog"
WordList = ["hot","dot","dog","lot","log"]

BFS Analysis:
Level 1: "hit" → "hot"
Level 2: "hot" → "dot", "hot" → "lot"
Level 3: "dot" → "dog", "lot" → "log" 
Level 4: No valid transformation to "cog"

Target "cog" not in wordList
No transformation sequence possible
```
**Output:**
```
0
```
