# Your task: Implement flood fill using DFS or BFS traversal to replace connected pixels of same color with new color starting from given coordinates.
def flood_fill():
    image_str = input("Enter the image grid as a nested list, e.g., [[1,1,1],[1,1,0],[1,0,1]]: ")
    image = eval(image_str)
    start_str = input("Enter the starting coordinates as a tuple, e.g., (1,1): ")
    sr, sc = eval(start_str)
    new_color = int(input("Enter the new color: "))
    
    rows, cols = len(image), len(image[0])
    original_color = image[sr][sc]
    
    if original_color == new_color:
        print("Output:", image)
        return

    q = [(sr, sc)]
    image[sr][sc] = new_color
    
    while q:
        r, c = q.pop(0)
        
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            if 0 <= nr < rows and 0 <= nc < cols and image[nr][nc] == original_color:
                image[nr][nc] = new_color
                q.append((nr, nc))

    print("Output:", image)

flood_fill()
