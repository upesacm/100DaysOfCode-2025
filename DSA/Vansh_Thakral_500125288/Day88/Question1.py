from typing import List

def floodFill(image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
    rows, cols = len(image), len(image[0])
    original_color = image[sr][sc]

    if original_color == newColor: 
        return image

    def dfs(r, c):
        if r < 0 or r >= rows or c < 0 or c >= cols:
            return
        if image[r][c] != original_color:
            return
        
        image[r][c] = newColor
        dfs(r+1, c)
        dfs(r-1, c)
        dfs(r, c+1)
        dfs(r, c-1)

    dfs(sr, sc)
    return image



print(floodFill([[1,1,1],[1,1,0],[1,0,1]], 1, 1, 2))

