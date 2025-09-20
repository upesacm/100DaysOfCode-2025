def topological_sort(graph, num_vertices):
    visited = [False] * num_vertices
    stack = []

    def dfs(node):
        visited[node] = True

        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs(neighbor)

        stack.append(node)  # Add after exploring all neighbors

    for i in range(num_vertices):
        if not visited[i]:
            dfs(i)

    # ----------------- FIXED BUG -----------------
    # The stack must be reversed because DFS pushes nodes AFTER visiting
    # all their neighbors. This creates a postorder sequence that is
    # reversed to form a valid topological ordering.
    return stack[::-1]
    # ---------------------------------------------


graph = {
    0: [1, 2],
    1: [3],
    2: [3],
    3: []
}

result = topological_sort(graph, 4)
print(f"Topological order: {result}")  # Expected: [0, 2, 1, 3] or [0, 1, 2, 3]


# ------------------- TASK ANSWERS -------------------

# 1. Identify the bug in the result order:
#    The original implementation returned the stack as-is,
#    which gives the reverse of the correct topological order.

# 2. Explain why the stack needs to be reversed for correct topological order:
#    In DFS-based topological sort, nodes are added to the stack only
#    after visiting all their neighbors. This results in a reverse
#    postorder sequence. Reversing it produces the correct topological order.

# 3. What is the correct way to return the topologically sorted vertices?
#    The correct way is to return "stack[::-1]" instead of "stack".
