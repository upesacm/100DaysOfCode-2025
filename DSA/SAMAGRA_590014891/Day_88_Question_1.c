#include <stdio.h>

#define ROWS 3
#define COLS 3

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

void dfs(int image[ROWS][COLS], int r, int c, int oldColor, int newColor) {
    if (r < 0 || c < 0 || r >= ROWS || c >= COLS) return;
    if (image[r][c] != oldColor) return;

    image[r][c] = newColor;
    for (int i = 0; i < 4; i++) {
        dfs(image, r + dr[i], c + dc[i], oldColor, newColor);
    }
}

void printImage(int image[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int image[ROWS][COLS] = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, newColor = 2;
    int oldColor = image[sr][sc];

    if (oldColor != newColor)
        dfs(image, sr, sc, oldColor, newColor);

    printImage(image);
    return 0;
}
