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

    # Correct way: reverse the stack before returning
    return stack[::-1]


if __name__ == "__main__":
    graph = {
        0: [1, 2],
        1: [3],
        2: [3],
        3: []
    }

    result = topological_sort(graph, 4)
    print("Topological order:", result)

"""
Answers 

1. The bug in the earlier version:
   It directly returned the stack. But the DFS puts finished nodes
   at the end, so the order was reversed.

2. Why we must reverse:
   The first node finished should actually come first in topological
   order, not last. Reversing fixes this.

3. Correct way:
   In Python, just return stack[::-1]. That gives the proper
   topological order.
"""
