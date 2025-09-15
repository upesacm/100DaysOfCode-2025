from collections import deque

def flood_fill(image, sr, sc, newcolour):   # sr and sc is starting_row and starting_column respectively.
    rows, columns = len(image), len(image[0])
    original_colour = image[sr][sc]

    # If the starting pixel is already the new colour, no need to change.
    if original_colour == newcolour:
        return image
    
    # BFS queue
    queue = deque([(sr, sc)])
    image[sr][sc] = newcolour

    # Directions : up, down, left, right
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    while queue:
        r, c = queue.popleft()
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            if 0 <= nr < rows and 0 <= nc < columns and image[nr][nc] == original_colour:
                image[nr][nc] = newcolour
                queue.append((nr, nc))

    return image

try:
    rows, columns = map(int, input("Enter the grid size (rows and columns) : ").split())
    print("Enter the grid row by row : ")
    image = []
    for _ in range(rows):
        image.append(list(map(int, input().split())))

    sr, sc = map(int, input("Enter the starting pixel (row column) : ").split())
    new_Colour = int(input("Enter the new colour : "))
    print(flood_fill(image, sr, sc, new_Colour))
except:
    print("Invalid input. Please try with a valid input.")
