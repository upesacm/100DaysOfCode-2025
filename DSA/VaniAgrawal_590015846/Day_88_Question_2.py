# Your task: Implement DFS-based island counting to identify and count all distinct connected land regions in the binary grid.
def number_of_islands():
    grid_str = input("Enter the grid as a nested list, e.g., [[1,1,0,0],[1,0,0,1],[0,0,1,1]]: ")
    grid = eval(grid_str)
    
    if not grid or not grid[0]:
        print("Output:", 0)
        return
    
    rows, cols = len(grid), len(grid[0])
    count = 0
    
    def dfs(r, c):
        if r < 0 or r >= rows or c < 0 or c >= cols or grid[r][c] == 0:
            return
        
        grid[r][c] = 0 
        dfs(r + 1, c)
        dfs(r - 1, c)
        dfs(r, c + 1)
        dfs(r, c - 1)
    
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                count += 1
                dfs(r, c)
                
    print("Output:", count)

number_of_islands()
