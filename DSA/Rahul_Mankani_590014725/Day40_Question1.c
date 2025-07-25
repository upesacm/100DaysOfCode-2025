#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int knows(int m[][MAX], int a, int b) 
{
    return m[a][b];
}
int Celebrity(int m[][MAX], int n) 
{
    int s[MAX], top = -1;
    for(int i = 0; i < n; i++) s[++top] = i;
    while(top > 0) 
    {
        int a = s[top--];
        int b = s[top];
        if(knows(m, a, b)) s[top] = b;
        else s[top] = a;
    }
    int c = s[0];
    for(int i = 0; i < n; i++) 
    {
        if(i != c && (knows(m, c, i) || !knows(m, i, c))) return -1;
    }
    return c;
}
int main() 
{
    int n;
    scanf("%d", &n);
    int m[MAX][MAX];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &m[i][j]);
    int c = Celebrity(m, n);
    printf("%d\n", c);
    return 0;
}
