#include <stdio.h>
#include <stdlib.h>

void dfsFloodFill(int** image, int rows, int cols, int sr, int sc, int oldColor, int newColor) {
    if (sr < 0 || sr >= rows || sc < 0 || sc >= cols || image[sr][sc] != oldColor || image[sr][sc] == newColor) {
        return;
    }
    
    image[sr][sc] = newColor;
    
    dfsFloodFill(image, rows, cols, sr+1, sc, oldColor, newColor);
    dfsFloodFill(image, rows, cols, sr-1, sc, oldColor, newColor);
    dfsFloodFill(image, rows, cols, sr, sc+1, oldColor, newColor);
    dfsFloodFill(image, rows, cols, sr, sc-1, oldColor, newColor);
}

void floodFill(int** image, int rows, int cols, int sr, int sc, int newColor) {
    if (rows == 0 || cols == 0) return;
    int oldColor = image[sr][sc];
    dfsFloodFill(image, rows, cols, sr, sc, oldColor, newColor);
}

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    
    int** image = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        image[i] = (int*)malloc(cols * sizeof(int));
    }
    
    printf("Enter the image grid (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &image[i][j]);
        }
    }
    
    int sr, sc, newColor;
    printf("Enter starting row coordinate: ");
    scanf("%d", &sr);
    printf("Enter starting column coordinate: ");
    scanf("%d", &sc);
    printf("Enter new color: ");
    scanf("%d", &newColor);
    
    floodFill(image, rows, cols, sr, sc, newColor);
    
    printf("Output:\n");
    for (int i = 0; i < rows; i++) {
        printf("[");
        for (int j = 0; j < cols; j++) {
            printf("%d", image[i][j]);
            if (j < cols - 1) printf(",");
        }
        printf("]");
        if (i < rows - 1) printf(",");
        printf("\n");
    }
    
    for (int i = 0; i < rows; i++) {
        free(image[i]);
    }
    free(image);
    return 0;
}
