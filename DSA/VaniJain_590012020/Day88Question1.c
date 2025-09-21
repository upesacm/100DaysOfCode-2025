#include <stdio.h>
#define MAX 100
int rows, cols;
int image[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void floodFill(int x, int y, int oldColor, int newColor) 
{
    if (x < 0 || x >= rows || y < 0 || y >= cols) return;
    if (image[x][y] != oldColor) return;
    image[x][y] = newColor;
    for (int i = 0; i < 4; i++) 
    {
        floodFill(x + dx[i], y + dy[i], oldColor, newColor);
    }
}
int main() 
{
    int startX, startY, newColor;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter the image grid (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            scanf("%d", &image[i][j]);
        }
    }
    printf("Enter starting pixel (row col): ");
    scanf("%d %d", &startX, &startY);
    printf("Enter new color: ");
    scanf("%d", &newColor);
    int oldColor = image[startX][startY];

    if (oldColor != newColor) 
    {
        floodFill(startX, startY, oldColor, newColor);
    }
    printf("\nImage after Flood Fill:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    return 0;
}
