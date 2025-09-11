#include <stdio.h>

#define ROWS 3
#define COLS 3

int image[ROWS][COLS] = {
    {1, 1, 1},
    {1, 1, 0},
    {1, 0, 1}
};

void dfs(int x, int y, int oldColor, int newColor) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) return;
    if (image[x][y] != oldColor) return;

    image[x][y] = newColor;

    dfs(x + 1, y, oldColor, newColor);
    dfs(x - 1, y, oldColor, newColor);
    dfs(x, y + 1, oldColor, newColor);
    dfs(x, y - 1, oldColor, newColor);
}

void floodFill(int startX, int startY, int newColor) {
    int oldColor = image[startX][startY];
    if (oldColor == newColor) return;
    dfs(startX, startY, oldColor, newColor);
}

int main() {
    int startX = 1, startY = 1, newColor = 2;

    floodFill(startX, startY, newColor);

    printf("Updated Image:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    return 0;
}

