#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int image[ROWS][COLS] = {{1,1,1},{1,1,0},{1,0,1}};
int newColor = 2;

void dfs(int r, int c, int oldColor) {
    if (r < 0 || c < 0 || r >= ROWS || c >= COLS) return;
    if (image[r][c] != oldColor) return;

    image[r][c] = newColor;

    dfs(r+1, c, oldColor);
    dfs(r-1, c, oldColor);
    dfs(r, c+1, oldColor);
    dfs(r, c-1, oldColor);
}

void printImage() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int startRow = 1, startCol = 1;
    int oldColor = image[startRow][startCol];

    if (oldColor != newColor)
        dfs(startRow, startCol, oldColor);

    printf("Flood Filled Image:\n");
    printImage();

    return 0;
}
