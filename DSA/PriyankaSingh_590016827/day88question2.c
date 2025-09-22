#include <stdbool.h>

void dfsIsland(char** grid, int m, int n, int r, int c) {
    if (r < 0 || c < 0 || r >= m || c >= n) return;
    if (grid[r][c] != '1') return;

    grid[r][c] = '0'; // mark visited

    dfsIsland(grid, m, n, r+1, c);
    dfsIsland(grid, m, n, r-1, c);
    dfsIsland(grid, m, n, r, c+1);
    dfsIsland(grid, m, n, r, c-1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = *gridColSize;
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfsIsland(grid, m, n, i, j);
            }
        }
    }
    return count;
}
