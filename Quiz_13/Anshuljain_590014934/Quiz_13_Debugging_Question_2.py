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

    return stack


graph = {
    0: [1, 2],
    1: [3],
    2: [3],
    3: []
}

result = topological_sort(graph, 4)
print(f"Topological order: {result}")

#Task Answer:
# Bug: The result is reversed because nodes are appended after exploring their neighbors.
# Reason: The DFS appends nodes in postorder, so the stack must be reversed to get correct topological order.
# Correct way: Return stack[::-1] instead of stack.
