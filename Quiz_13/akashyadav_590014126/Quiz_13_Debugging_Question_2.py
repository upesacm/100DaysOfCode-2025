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

    return stack[::-1]

graph = {
    0: [1, 2],
    1: [3],
    2: [3],
    3: []
}

result = topological_sort(graph, 4)
print(f"Topological order: {result}")

#1.Bug in order: The original function returns nodes in 'reversed postorder' of DFS,
#which is NOT the correct topological order since the required property is for every edge u->v, u appears before v[web:37][web:40][web:42][web:46][web:50].
#2.Why reverse the stack: DFS adds nodes after visiting all descendants.
#Reversing the stack ensures dependencies appear before dependents, which is the requirement for topological sort[web:37][web:46][web:50].
#3.Correct way to return: At the end of DFS, return stack[::-1] for proper topological sorting[web:37][web:46][web:50].
