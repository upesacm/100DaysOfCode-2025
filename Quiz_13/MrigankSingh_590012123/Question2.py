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

    # BUG FIX: Reverse the stack to get correct topological order
    # The stack contains nodes in order of finishing times (sinks first, sources last)
    # Reversing gives the proper topological order (sources first, sinks last)
    return stack[::-1]

graph = {
    0: [1, 2],
    1: [3],
    2: [3],
    3: []
}

result = topological_sort(graph, 4)
print(f"Topological order: {result}")
# Expected: [0, 2, 1, 3] or [0, 1, 2, 3] (depending on traversal order)

# TASKS EXPLANATION:
# 1. The bug is that the function returns nodes in reverse topological order
#    (sinks first, sources last) instead of the correct topological order.
# 2. The stack needs to be reversed because in DFS we append nodes after processing
#    all descendants, so sinks are added first and sources last.
# 3. The correct way is to return the reversed stack (stack[::-1]) to get the
#    proper topological order where sources come before sinks.
