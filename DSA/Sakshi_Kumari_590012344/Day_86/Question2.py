from collections import defaultdict

class Graph:
    def __init__(self, n):
        self.n = n
        self.g = defaultdict(list)

    def addEdge(self, u, v):
        self.g[u].append(v)

    def dfs(self, node, vis, stack):
        vis[node] = True
        stack[node] = True
        for nxt in self.g[node]:
            if not vis[nxt]:
                if self.dfs(nxt, vis, stack):
                    return True
            elif stack[nxt]:
                return True
        stack[node] = False
        return False

    def detectCycle(self):
        vis = [False] * self.n
        stack = [False] * self.n
        for i in range(self.n):
            if not vis[i]:
                if self.dfs(i, vis, stack):
                    return True
        return False
