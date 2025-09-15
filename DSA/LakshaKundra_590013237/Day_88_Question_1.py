def flood_fill(image, sr, sc, new_color):
    rows, cols = len(image), len(image[0])
    old_color = image[sr][sc]
    if old_color == new_color:
        return image
    def dfs(r, c):
        if r < 0 or r >= rows or c < 0 or c >= cols or image[r][c] != old_color:
            return
        image[r][c] = new_color
        dfs(r+1, c)
        dfs(r-1, c)
        dfs(r, c+1)
        dfs(r, c-1)
    dfs(sr, sc)
    return image

print(flood_fill([[1,1,1],[1,1,0],[1,0,1]], 1, 1, 2))
print(flood_fill([[0,0,0],[0,0,0]], 0, 0, 1))
