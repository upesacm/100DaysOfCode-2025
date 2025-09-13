def numIslands(grid):
    if not grid:
        return 0
    
    rows, cols = len(grid), len(grid[0])
    visited = [[False]*cols for _ in range(rows)]
    
    def dfs(r, c):
        if r < 0 or r >= rows or c < 0 or c >= cols:
            return
        if grid[r][c] == 0 or visited[r][c]:
            return
        visited[r][c] = True
        dfs(r+1, c)
        dfs(r-1, c)
        dfs(r, c+1)
        dfs(r, c-1)
    
    count = 0
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1 and not visited[r][c]:
                dfs(r, c)
                count += 1
    return count


rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))

print("Enter the grid row by row (space-separated, use 1 for land and 0 for water):")
grid = [list(map(int, input().split())) for _ in range(rows)]

result = numIslands(grid)

print("Number of distinct islands found:", result)
