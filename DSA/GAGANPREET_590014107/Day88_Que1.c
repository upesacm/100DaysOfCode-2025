#include <stdio.h>

#define ROWS 3
#define COLS 3

void dfs(int image[ROWS][COLS], int r, int c, int originalColor, int newColor) {
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS || image[r][c] != originalColor)
        return;

    image[r][c] = newColor;

    dfs(image, r + 1, c, originalColor, newColor); 
    dfs(image, r - 1, c, originalColor, newColor);
    dfs(image, r, c + 1, originalColor, newColor); 
    dfs(image, r, c - 1, originalColor, newColor); 
}

void floodFill(int image[ROWS][COLS], int sr, int sc, int newColor) {
    int originalColor = image[sr][sc];
    if (originalColor != newColor)
        dfs(image, sr, sc, originalColor, newColor);
}

void printImage(int image[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int image[ROWS][COLS] = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int startRow = 1, startCol = 1, newColor = 2;

    printf("Original Image:\n");
    printImage(image);

    floodFill(image, startRow, startCol, newColor);

    printf("\nFlood-Filled Image:\n");
    printImage(image);

    return 0;
}
