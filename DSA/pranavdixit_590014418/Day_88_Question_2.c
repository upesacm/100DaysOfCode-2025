#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int grid[ROWS][COLS] = {
    {1,1,0,0},
    {1,0,0,1},
    {0,0,1,1}
};
int visited[ROWS][COLS];

void dfs(int r, int c) {
    if (r < 0 || c < 0 || r >= ROWS || c >= COLS) return;
    if (grid[r][c] == 0 || visited[r][c]) return;

    visited[r][c] = 1;

    dfs(r+1, c);
    dfs(r-1, c);
    dfs(r, c+1);
    dfs(r, c-1);
}

int countIslands() {
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                dfs(i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    printf("Number of Islands: %d\n", countIslands());
    return 0;
}
