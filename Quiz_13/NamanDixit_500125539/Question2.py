#1. The function returns the stack in the order nodes are finished ([3, 1, 2, 0]), which is the reverse of the correct topological order.

#2. Why reverse is needed: In DFS-based topological sort, nodes are pushed after exploring all descendants.
# This means the stack holds nodes in reverse finishing order. Reversing gives the correct dependency order.

#3. Corected way = return stack[::-1]

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
