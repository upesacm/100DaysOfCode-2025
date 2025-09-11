def number_of_islands(grid):
    if not grid:
        return 0
    
    rows, columns = len(grid), len(grid[0])
    
    def DFS(r, c):
        # boundary + water check
        if r < 0 or r >= rows or c < 0 or c >= columns or grid[r][c] == 0:
            return
        # mark current land as visited (turn to water)
        grid[r][c] = 0
        # explore neighbours (up, down, left, right)
        DFS(r - 1, c)
        DFS(r + 1, c)
        DFS(r, c - 1)
        DFS(r, c + 1)

    islands = 0
    for i in range(rows):
        for j in range(columns):
            if grid[i][j] == 1:  # found land
                islands += 1
                DFS(i, j)  # sink the island
    return islands

try:
    rows, columns = map(int, input("Enter the grid size (rows and columns) : ").split())
    print("Enter the grid row by row (0 for water, 1 for land): ")
    grid = []
    for _ in range(rows):
        grid.append(list(map(int, input().split())))

    print(number_of_islands(grid))
except:
    print("Invalid input. Please try with a valid input.")
