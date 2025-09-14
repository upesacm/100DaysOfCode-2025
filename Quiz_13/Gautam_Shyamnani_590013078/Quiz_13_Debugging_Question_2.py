def topological_sort(graph, num_vertices):
    visited = [False] * num_vertices
    stack = []

    def dfs(node):
        visited[node] = True
        for neighbor in graph.get(node, []):  
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
print("Topological order:", result)
