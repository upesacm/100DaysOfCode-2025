from typing import List
from collections import deque

def isBipartite(V: int, edges: List[List[int]]) -> bool:
    graph = [[] for _ in range(V)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    color = [-1] * V  # -1 = uncolored, 0 or 1 = two colors

    for start in range(V):
        if color[start] == -1:  # not yet visited
            queue = deque([start])
            color[start] = 0
            while queue:
                node = queue.popleft()
                for nei in graph[node]:
                    if color[nei] == -1:
                        color[nei] = 1 - color[node]  # alternate color
                        queue.append(nei)
                    elif color[nei] == color[node]:
                        return False
    return True


# Example 1
print(isBipartite(4, [[0,1],[1,2],[2,3],[3,0]]))  # True

# Example 2
print(isBipartite(3, [[0,1],[1,2],[2,0]]))        # False
