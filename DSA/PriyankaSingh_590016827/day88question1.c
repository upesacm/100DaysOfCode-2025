#include <stdio.h>

#define MAXN 100

int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfsFlood(int** image, int m, int n, int r, int c, int oldColor, int newColor) {
    if (r < 0 || c < 0 || r >= m || c >= n) return;
    if (image[r][c] != oldColor) return;

    image[r][c] = newColor;

    for (int d = 0; d < 4; d++) {
        dfsFlood(image, m, n, r + dirs[d][0], c + dirs[d][1], oldColor, newColor);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int m = imageSize, n = *imageColSize;
    *returnSize = m;
    *returnColumnSizes = imageColSize;

    int oldColor = image[sr][sc];
    if (oldColor != color) {
        dfsFlood(image, m, n, sr, sc, oldColor, color);
    }

    return image;
}
