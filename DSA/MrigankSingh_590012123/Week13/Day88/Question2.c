#include <stdio.h>
#include <stdlib.h>

void dfsIsland(int** grid, int rows, int cols, int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 1) {
        return;
    }
    
    grid[r][c] = 0; // Mark as visited
    
    dfsIsland(grid, rows, cols, r+1, c);
    dfsIsland(grid, rows, cols, r-1, c);
    dfsIsland(grid, rows, cols, r, c+1);
    dfsIsland(grid, rows, cols, r, c-1);
}

int countIslands(int** grid, int rows, int cols) {
    if (rows == 0 || cols == 0) return 0;
    
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                dfsIsland(grid, rows, cols, i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    
    int** grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
    }
    
    printf("Enter the binary grid (%d x %d, 0 for water, 1 for land):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    printf("Number of islands: %d\n", countIslands(grid, rows, cols));
    
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}
