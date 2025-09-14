# Your task: Implement Kosaraju's algorithm using two DFS passes on original and transpose graphs to identify all strongly connected components.
from collections import defaultdict

def kosarajus_algorithm():
    num_vertices = int(input("Enter the number of vertices: "))
    edges_str = input("Enter the edges as a list of tuples (u, v): ")
    edges = eval(edges_str)

    adj = defaultdict(list)
    rev_adj = defaultdict(list)
    for u, v in edges:
        adj[u].append(v)
        rev_adj[v].append(u)

    stack = []
    visited = [False] * num_vertices
    
    def dfs1(u):
        visited[u] = True
        for v in adj[u]:
            if not visited[v]:
                dfs1(v)
        stack.append(u)

    for i in range(num_vertices):
        if not visited[i]:
            dfs1(i)

    visited = [False] * num_vertices
    count = 0

    def dfs2(u):
        visited[u] = True
        for v in rev_adj[u]:
            if not visited[v]:
                dfs2(v)

    while stack:
        u = stack.pop()
        if not visited[u]:
            dfs2(u)
            count += 1
            
    print("Output:", count)

kosarajus_algorithm()
