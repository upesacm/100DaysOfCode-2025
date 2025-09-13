def floodFillDFS(image, sr, sc, newColor):
    rows, cols = len(image), len(image[0])
    original = image[sr][sc]
    if original == newColor:
        return image

    def dfs(r, c):
        if r < 0 or r >= rows or c < 0 or c >= cols or image[r][c] != original:
            return
        image[r][c] = newColor
        for dr, dc in [(0,1), (1,0), (0,-1), (-1,0)]:
            dfs(r + dr, c + dc)

    dfs(sr, sc)
    return image
