#include <stdio.h>

#define MAX 99

int image[MAX][MAX];
int n, m, oldColor, newColor;

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || image[x][y] != oldColor) return;
    image[x][y] = newColor;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main() {
    int startX, startY;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &image[i][j]);
    scanf("%d %d %d", &startX, &startY, &newColor);
    oldColor = image[startX][startY];
    if (oldColor != newColor)
        dfs(startX, startY);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", image[i][j]);
        printf("\n");
    }
    return 0;
}
