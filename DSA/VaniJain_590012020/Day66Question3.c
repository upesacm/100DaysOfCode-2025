#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) { return (a > b) ? a : b; }
int main() 
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        fprintf(stderr, "Invalid number of children.\n");
        return 1;
    }
    int ratings[n];
    for (int i = 0; i < n; i++) 
    {
        if (scanf("%d", &ratings[i]) != 1) 
        {
            fprintf(stderr, "Invalid input.\n");
            return 1;
        }
    }
    int candies[n];
    for (int i = 0; i < n; i++) 
    {
        candies[i] = 1;
    }
    for (int i = 1; i < n; i++) 
    {
        if (ratings[i] > ratings[i - 1]) 
        {
            candies[i] = candies[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--) 
    {
        if (ratings[i] > ratings[i + 1]) 
        {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }
    int total = 0;
    for (int i = 0; i < n; i++) 
    {
        total += candies[i];
    }
    printf("Minimum Candies Needed: %d\n", total);
    printf("Candies Distribution: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", candies[i]);
    }
    printf("\n");
    return 0;
}
