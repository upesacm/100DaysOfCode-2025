#answer 1
#stack is not reversed, giving reversed order.

#answer 2
#Reversal is required because DFS stores nodes after visiting neighbors (post-order), so stack holds reverse order.

#answer 3
#The correct way:
#stack.reverse()
#return stack

#correct code 
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
