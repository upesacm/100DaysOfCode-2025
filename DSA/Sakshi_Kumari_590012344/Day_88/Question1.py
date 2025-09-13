def flood_fill(image, row, col, new_color):
    start_color = image[row][col]
    if start_color == new_color:
        return image

    rows = len(image)
    cols = len(image[0])

    def dfs(r, c):
        if r < 0 or r >= rows or c < 0 or c >= cols:
            return
        if image[r][c] != start_color:
            return
        image[r][c] = new_color
        dfs(r + 1, c)
        dfs(r - 1, c)
        dfs(r, c + 1)
        dfs(r, c - 1)

    dfs(row, col)
    return image
