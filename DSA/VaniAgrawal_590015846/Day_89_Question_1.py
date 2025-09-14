# Your task: Implement Kruskal's algorithm using edge sorting and union-find to construct minimum spanning tree with optimal total weight.
def kruskals_algorithm():
    num_vertices = int(input("Enter the number of vertices: "))
    edges_str = input("Enter the edges as a list of tuples (u, v, weight): ")
    edges = eval(edges_str)

    parent = list(range(num_vertices))
    
    def find(i):
        if parent[i] == i:
            return i
        parent[i] = find(parent[i])
        return parent[i]
        
    def union(i, j):
        root_i = find(i)
        root_j = find(j)
        if root_i != root_j:
            parent[root_j] = root_i
            return True
        return False
        
    edges.sort(key=lambda x: x[2])
    mst_cost = 0
    num_edges = 0
    
    for u, v, weight in edges:
        if union(u, v):
            mst_cost += weight
            num_edges += 1
            if num_edges == num_vertices - 1:
                break
    
    print("Output:", mst_cost)

kruskals_algorithm()
