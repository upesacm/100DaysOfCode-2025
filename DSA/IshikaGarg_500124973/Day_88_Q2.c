#include <stdio.h>

#define ROWS 3
#define COLS 4

int grid[ROWS][COLS] = {
    {1,1,0,0},
    {1,0,0,1},
    {0,0,1,1}
};

int visited[ROWS][COLS];

void dfsIsland(int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) return;
    if (grid[x][y] == 0 || visited[x][y]) return;

    visited[x][y] = 1;

    dfsIsland(x+1, y);
    dfsIsland(x-1, y);
    dfsIsland(x, y+1);
    dfsIsland(x, y-1);
}

int countIslands() {
    int count = 0;
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                dfsIsland(i, j);
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

