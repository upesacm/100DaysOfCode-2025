from collections import deque

def floodFill(image, sr, sc, newColor):
    rows, cols = len(image), len(image[0])
    start_color = image[sr][sc]
    if start_color == newColor:
        return image
    
    q = deque([(sr, sc)])
    image[sr][sc] = newColor
    
    while q:
        r, c = q.popleft()
        for dr, dc in [(1,0),(-1,0),(0,1),(0,-1)]:
            nr, nc = r+dr, c+dc
            if 0 <= nr < rows and 0 <= nc < cols and image[nr][nc] == start_color:
                image[nr][nc] = newColor
                q.append((nr, nc))
    return image


rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))

print("Enter the image grid row by row (space-separated numbers):")
image = [list(map(int, input().split())) for _ in range(rows)]

sr, sc = map(int, input("Enter starting pixel coordinates (row col): ").split())
newColor = int(input("Enter new color: "))

result = floodFill(image, sr, sc, newColor)

print("Image after filling:", result)
