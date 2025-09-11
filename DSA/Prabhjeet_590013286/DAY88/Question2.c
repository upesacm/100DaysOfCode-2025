#include <stdio.h>

void dfs(int** grid, int rows, int cols, int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) return;
    if (grid[r][c] != 1) return;

    grid[r][c] = -1; // Mark visited

    dfs(grid, rows, cols, r+1, c);
    dfs(grid, rows, cols, r-1, c);
    dfs(grid, rows, cols, r, c+1);
    dfs(grid, rows, cols, r, c-1);
}

int countIslands(int** grid, int rows, int cols) {
    int count = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 1) {
                dfs(grid, rows, cols, r, c);
                count++;
            }
        }
    }
    return count;
}
