def topological_sort(graph, num_vertices):
    visited = [False] * num_vertices
    stack = []

    def dfs(node):
        visited[node] = True

        if node in graph:
            for neighbor in graph[node]:
                if not visited[neighbor]:
                    dfs(neighbor)
        
        stack.append(node)

    for i in range(num_vertices):
        if not visited[i]:
            dfs(i)

    return stack[::-1]

# Test case:
graph = {
    0: [1, 2],
    1: [3],
    2: [3],
    3: []
}

result = topological_sort(graph, 4)
print(f"Topological order: {result}")

# Tasks:
# 1. Identify the bug in the result order.
# The bug is that the original code returns a reverse topological sort. This happens because
# the DFS traversal adds a node to the stack only after all of its descendants have been 
# visited. This post-order traversal order is the exact reverse of a topological sort. 
# For a topological sort, a node must appear before its neighbors.

# 2. Explain why the stack needs to be reversed for a correct topological order.
# The stack needs to be reversed because of the nature of the DFS traversal. DFS 
# explores a path as deeply as possible before backtracking. This means a node's
# children are fully processed and added to the stack before the parent node is added. 
# Reversing the stack places the parent nodes before their children, correctly 
# representing the dependency order. 

# 3. What is the correct way to return the topologically sorted vertices?
# The correct way to return the topologically sorted vertices is to return the reversed
# stack. The line `return stack[::-1]` in the corrected code achieves this, providing a
# valid topological ordering.
