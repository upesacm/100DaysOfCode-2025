#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
long long maxArea(int h[], int n) 
{
    int s[MAX], top = -1;
    long long max_area = 0;
    for(int i = 0; i <= n; i++) 
    {
        while(top >= 0 && (i == n || h[s[top]] > h[i])) 
        {
            int height = h[s[top--]];
            int width = top >= 0 ? i - s[top] - 1 : i;
            max_area = (long long)height * width > max_area ? (long long)height * width : max_area;
        }
        s[++top] = i;
    }
    return max_area;
}
int main() 
{
    int n;
    scanf("%d", &n);
    int h[n];
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &h[i]);
    }
    printf("%lld\n", maxArea(h, n));
    return 0;
}
