#include <stdio.h>

#define ROWS 3
#define COLS 4

int dr2[] = {1, -1, 0, 0};
int dc2[] = {0, 0, 1, -1};

void dfsIsland(int grid[ROWS][COLS], int r, int c) {
    if (r < 0 || c < 0 || r >= ROWS || c >= COLS) return;
    if (grid[r][c] == 0) return;

    grid[r][c] = 0; 
    for (int i = 0; i < 4; i++) {
        dfsIsland(grid, r + dr2[i], c + dc2[i]);
    }
}

int countIslands(int grid[ROWS][COLS]) {
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                count++;
                dfsIsland(grid, i, j);
            }
        }
    }
    return count;
}

int main() {
    int grid[ROWS][COLS] = {{1,1,0,0},{1,0,0,1},{0,0,1,1}};
    printf("Number of Islands = %d\n", countIslands(grid));
    return 0;
}
