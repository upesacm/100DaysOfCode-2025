Task 1: Identify the bug in the result order

The bug is that the function returns stack directly.

In DFS-based topological sorting, nodes are appended in postorder → meaning the stack contains nodes in reverse topological order.

Example:
For the given graph

0 → 1 → 3
 \        ↑
  → 2 ----


The returned stack might look like:

[3, 1, 2, 0]


But the correct topological order is:

[0, 2, 1, 3]   (or [0, 1, 2, 3] depending on DFS path)


Task 2: Why the stack needs to be reversed

In DFS topological sort, we push a node after all its dependencies (children) are processed.

That means the first element in the stack is a “sink” node, not a “source” node.

Reversing ensures we get the correct ordering: dependencies before dependents.

So, the stack needs to be reversed before returning.

Task 3: Correct way to return

Modify the return statement to:

return stack[::-1]   # reverse the stack

#Correct Code
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

    return stack[::-1]   # reverse before returning


graph = {
    0: [1, 2],
    1: [3],
    2: [3],
    3: []
}

result = topological_sort(graph, 4)
print(f"Topological order: {result}")

Output:
Topological order: [0, 2, 1, 3]
