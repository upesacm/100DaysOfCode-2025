def num_islands(grid):
    rows, cols = len(grid), len(grid[0])
    visited = [[False]*cols for _ in range(rows)]
    def dfs(r, c):
        if r<0 or r>=rows or c<0 or c>=cols or grid[r][c]==0 or visited[r][c]:
            return
        visited[r][c] = True
        dfs(r+1,c)
        dfs(r-1,c)
        dfs(r,c+1)
        dfs(r,c-1)
    count = 0
    for r in range(rows):
        for c in range(cols):
            if grid[r][c]==1 and not visited[r][c]:
                dfs(r,c)
                count += 1
    return count

print(num_islands([[1,1,0,0],[1,0,0,1],[0,0,1,1]]))
print(num_islands([[1,1,0],[0,1,0],[0,0,1]]))
