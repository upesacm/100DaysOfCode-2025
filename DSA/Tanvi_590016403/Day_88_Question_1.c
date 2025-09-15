from collections import deque

class cc:

    # 1. Flood Fill
    def flood_fill(self, image, start, new_color):
        rows, cols = len(image), len(image[0])
        start_r, start_c = start
        original = image[start_r][start_c]
        if original == new_color:
            return image

        def dfs(r, c):
            if (r < 0 or r >= rows or c < 0 or c >= cols or image[r][c] != original):
                return
            image[r][c] = new_color
            dfs(r+1, c); dfs(r-1, c)
            dfs(r, c+1); dfs(r, c-1)

        dfs(start_r, start_c)
        return image

    # 2. Number of Islands
    def num_islands(self, grid):
        if not grid:
            return 0
        rows, cols = len(grid), len(grid[0])
        visited = [[False]*cols for _ in range(rows)]

        def dfs(r, c):
            if r < 0 or r >= rows or c < 0 or c >= cols or grid[r][c] == 0 or visited[r][c]:
                return
            visited[r][c] = True
            dfs(r+1, c); dfs(r-1, c)
            dfs(r, c+1); dfs(r, c-1)

        count = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1 and not visited[r][c]:
                    dfs(r, c)
                    count += 1
        return count

    # 3. Bipartite Graph Check
    def is_bipartite(self, vertices, edges):
        graph = [[] for _ in range(vertices)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        color = [-1] * vertices

        def bfs(start):
            q = deque([start])
            color[start] = 0
            while q:
                node = q.popleft()
                for nei in graph[node]:
                    if color[nei] == -1:
                        color[nei] = 1 - color[node]
                        q.append(nei)
                    elif color[nei] == color[node]:
                        return False
            return True

        for v in range(vertices):
            if color[v] == -1:
                if not bfs(v):
                    return False
        return True


# -------------------------------
# Example Usage
# -------------------------------
obj = cc()

# Flood Fill Example
image = [[1,1,1],[1,1,0],[1,0,1]]
print("Flood Fill Result:", obj.flood_fill(image, (1,1), 2))

# Number of Islands Example
grid = [[1,1,0,0],[1,0,0,1],[0,0,1,1]]
print("Number of Islands:", obj.num_islands(grid))

# Bipartite Graph Example
vertices = 4
edges = [[0,1],[1,2],[2,3],[3,0]]
print("Is Graph Bipartite?", obj.is_bipartite(vertices, edges))
