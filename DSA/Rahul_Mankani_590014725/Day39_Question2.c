#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
void spans(int p[], int n, int s[]) 
{
    int st[MAX], top = -1;
    
    for(int i = 0; i < n; i++) 
    {
        while(top >= 0 && p[st[top]] <= p[i]) 
        {
            top--;
        }
        s[i] = (top >= 0) ? i - st[top] - 1 : i;
        st[++top] = i;
    }
}
int main() 
{
    int n;
    scanf("%d", &n);
    int p[n], s[n];
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &p[i]);
    }
    spans(p, n, s);
    for(int i = 0; i < n; i++) 
    {
        printf("%d ", s[i]);
    }
    printf("\n");
    return 0;
}
