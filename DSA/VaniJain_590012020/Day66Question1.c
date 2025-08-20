#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int cmp_int(const void *a, const void *b) 
{
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}
static int parse_time(const char *s) 
{
    int h = 0, m = 0;
    sscanf(s, "%d:%d", &h, &m);
    return h * 60 + m;
}
int main(void) 
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        fprintf(stderr, "Invalid number of trains.\n");
        return 1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    int *dep = (int *)malloc(n * sizeof(int));
    if (!arr || !dep) 
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) 
    {
        char buf[16];
        if (scanf("%15s", buf) != 1) { fprintf(stderr, "Bad input.\n"); return 1; }
        arr[i] = parse_time(buf);
    }
    for (int i = 0; i < n; i++) 
    {
        char buf[16];
        if (scanf("%15s", buf) != 1) { fprintf(stderr, "Bad input.\n"); return 1; }
        dep[i] = parse_time(buf);
    }
    qsort(arr, n, sizeof(int), cmp_int);
    qsort(dep, n, sizeof(int), cmp_int);
    int i = 0, j = 0;
    int platforms = 0, maxPlatforms = 0;
    while (i < n && j < n) 
    {
        if (arr[i] <= dep[j]) 
        {
            platforms++;
            if (platforms > maxPlatforms) maxPlatforms = platforms;
            i++;
        } 
        else 
        {
            platforms--;
            j++;
        }
    }
    printf("%d\n", maxPlatforms);
    free(arr);
    free(dep);
    return 0;
}
