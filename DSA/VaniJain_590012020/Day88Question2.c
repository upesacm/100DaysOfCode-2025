#include <stdio.h>
#define MAX 100
int rows, cols;
int grid[MAX][MAX];
int visited[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int x, int y) 
{
    if (x < 0 || x >= rows || y < 0 || y >= cols) return;
    if (visited[x][y] || grid[x][y] == 0) return;
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) 
    {
        dfs(x + dx[i], y + dy[i]);
    }
}
int countIslands() 
{
    int count = 0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (grid[i][j] == 1 && !visited[i][j]) 
            {
                dfs(i, j);
                count++;
            }
        }
    }
    return count;
}
int main() 
{
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter grid (%d x %d) with 0=water, 1=land:\n", rows, cols);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            scanf("%d", &grid[i][j]);
            visited[i][j] = 0;
        }
    }
    int islands = countIslands();
    printf("\nNumber of distinct islands = %d\n", islands);
    return 0;
}
