//Flood Fill (DFS)
#include <stdio.h>

void fill(int** image, int rows, int cols, int r, int c, int original, int newColor) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) return;
    if (image[r][c] != original) return;

    image[r][c] = newColor;

    fill(image, rows, cols, r+1, c, original, newColor);
    fill(image, rows, cols, r-1, c, original, newColor);
    fill(image, rows, cols, r, c+1, original, newColor);
    fill(image, rows, cols, r, c-1, original, newColor);
}

void floodFill(int** image, int rows, int cols, int sr, int sc, int newColor) {
    int original = image[sr][sc];
    if (original != newColor) {
        fill(image, rows, cols, sr, sc, original, newColor);
    }
}
