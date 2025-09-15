#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct Point { int x,y; };

int main() {
    int n,m,newColor,sx,sy;
    scanf("%d %d",&n,&m);
    int img[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&img[i][j]);
    scanf("%d %d",&sx,&sy);
    scanf("%d",&newColor);

    int oldColor = img[sx][sy];
    if(oldColor == newColor) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) printf("%d ",img[i][j]);
            printf("\n");
        }
        return 0;
    }

    struct Point q[MAX*MAX];
    int front=0,rear=0;
    q[rear++] = (struct Point){sx,sy};
    img[sx][sy] = newColor;

    while(front<rear) {
        struct Point p = q[front++];
        for(int k=0;k<4;k++) {
            int nx = p.x+dx[k], ny = p.y+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && img[nx][ny]==oldColor) {
                img[nx][ny] = newColor;
                q[rear++] = (struct Point){nx,ny};
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) printf("%d ",img[i][j]);
        printf("\n");
    }
    return 0;
}
