# Your task: Implement degree-based analysis to determine existence of Eulerian Path or Circuit using vertex degree counting and mathematical conditions.
def eulerian_path_circuit():
    num_vertices = int(input("Enter the number of vertices: "))
    edges_str = input("Enter the edges as a list of lists, e.g., [[0,1],[1,2],[2,0],[0,3]]: ")
    edges = eval(edges_str)
    
    degrees = [0] * num_vertices
    for u, v in edges:
        degrees[u] += 1
        degrees[v] += 1
    
    odd_degree_count = 0
    for degree in degrees:
        if degree % 2 != 0:
            odd_degree_count += 1
            
    if odd_degree_count == 0:
        print("Output: Eulerian Circuit Exists")
    elif odd_degree_count == 2:
        print("Output: Eulerian Path Exists")
    else:
        print("Output: No Eulerian Path or Circuit Exists")

eulerian_path_circuit()
