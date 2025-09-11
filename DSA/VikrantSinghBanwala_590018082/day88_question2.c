#include <stdio.h>

int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int** grid, int rows, int cols, int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) return;
    if (grid[r][c] == 0) return;
    grid[r][c] = 0;
    for (int i = 0; i < 4; i++) {
        dfs(grid, rows, cols, r + directions[i][0], c + directions[i][1]);
    }
}

int numIslands(int** grid, int gridSize, int* gridColSize) {
    int count = 0;
    int rows = gridSize;
    int cols = gridColSize[0];
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 1) {
                count++;
                dfs(grid, rows, cols, r, c);
            }
        }
    }
    return count;
}