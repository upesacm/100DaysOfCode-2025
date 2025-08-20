#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int a, b;
} Pair;
int compare(const void *x, const void *y) 
{
    Pair *p1 = (Pair *)x;
    Pair *p2 = (Pair *)y;
    return (p1->b - p2->b);
}
int maxChainLength(Pair arr[], int n) 
{
    qsort(arr, n, sizeof(Pair), compare);
    int count = 1;  
    int last = arr[0].b;
    for (int i = 1; i < n; i++) 
    {
        if (arr[i].a > last) 
        {
            count++;
            last = arr[i].b;
        }
    }
    return count;
}
int main() 
{
    int n;
    printf("Enter number of pairs: ");
    scanf("%d", &n);
    Pair arr[n];
    printf("Enter the pairs (a b):\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d %d", &arr[i].a, &arr[i].b);
    }
    int result = maxChainLength(arr, n);
    printf("\nMaximum length of chain: %d\n", result);
    return 0;
}

