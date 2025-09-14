# 1. Identify the bug in the result order.
# -The stack is not reversed before returning.

# 2. Explain why the stack needs to be reversed for correct topological order.
# -In DFS topological sort:
# Nodes are added to the stack after all their dependencies (children) are processed.
# This means the stack ends up with the last node first and the first node last.
# To get the correct topological order (from root to leaves), we must reverse the stack.

# 3. What is the correct way to return the topologically sorted vertices
# Just reverse the stack before returning:

def topological_sort(graph, num_vertices):
    visited = [False] * num_vertices
    stack = []

    def dfs(node):
        visited[node] = True
        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs(neighbor)
        stack.append(node)

    for i in range(num_vertices):
        if not visited[i]:
            dfs(i)

    return stack[::-1]  # Reverse for correct topological order