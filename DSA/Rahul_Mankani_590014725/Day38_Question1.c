#include <stdio.h>
#include <stdlib.h>

void nge(int a[], int n, int r[]) 
{
    int s[n], top = -1;
    for(int i = 0; i < n; i++) 
    {
        while(top >= 0 && a[s[top]] < a[i]) 
        {
            r[s[top]] = a[i];
            top--;
        }
        s[++top] = i;
    }
    while(top >= 0) 
    {
        r[s[top]] = -1;
        top--;
    }
}
int main() 
{
    int n;
    scanf("%d", &n);
    int a[n], r[n];
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
        r[i] = 0;
    }
    nge(a, n, r);
    for(int i = 0; i < n; i++) 
    {
        printf("%d ", r[i]);
    }
    printf("\n");
    return 0;
}
