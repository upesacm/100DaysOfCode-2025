#include <stdio.h>

#define ROWS 3
#define COLS 4

void dfs(int grid[ROWS][COLS], int visited[ROWS][COLS], int r, int c) {
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS)
        return;
    if (grid[r][c] == 0 || visited[r][c])
        return;

    visited[r][c] = 1;


    dfs(grid, visited, r + 1, c); // down
    dfs(grid, visited, r - 1, c); // up
    dfs(grid, visited, r, c + 1); // right
    dfs(grid, visited, r, c - 1); // left
}

int countIslands(int grid[ROWS][COLS]) {
    int visited[ROWS][COLS] = {0};
    int count = 0;

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (grid[r][c] == 1 && !visited[r][c]) {
                dfs(grid, visited, r, c);
                count++;
            }
        }
    }

    return count;
}

int main() {
    int grid[ROWS][COLS] = {
        {1, 1, 0, 0},
        {1, 0, 0, 1},
        {0, 0, 1, 1}
    };

    int result = countIslands(grid);
    printf("Number of islands: %d\n", result); // Output: 3

    return 0;
}
