#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
} Point;

int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if (oldColor == newColor) return;
    int rows = imageSize;
    int cols = imageColSize[0];
    Point* stack = (Point*)malloc(rows * cols * sizeof(Point));
    int top = 0;
    stack[top++] = (Point){sr, sc};
    while (top > 0) {
        Point p = stack[--top];
        int r = p.row, c = p.col;
        if (r < 0 || r >= rows || c < 0 || c >= cols) continue;
        if (image[r][c] != oldColor) continue;
        image[r][c] = newColor;
        for (int i = 0; i < 4; i++) {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];
            stack[top++] = (Point){nr, nc};
        }
    }
    free(stack);
}