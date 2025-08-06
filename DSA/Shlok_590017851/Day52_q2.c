#include <stdio.h>
#include <stdbool.h>

bool exists(int arr[], int n, int val)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) return true;
    }
    return false;
}
void findPairsWithDiff(int arr[], int n, int k)
{
    printf("Pairs with difference %d:\n", k);

    for (int i = 0; i < n; i++) 
    {
        int x = arr[i];
        
        if (exists(arr, n, x + k)) 
        {
            printf("(%d, %d)\n", x, x + k);
        }
        if (exists(arr, n, x - k)) 
        {
            printf("(%d, %d)\n", x, x - k);
        }
    }
}
int main() 
{
    int arr1[] = {1, 5, 3, 4, 2};
    int k1 = 2;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    findPairsWithDiff(arr1, n1, k1);

    printf("\n");

    int arr2[] = {8, 12, 16, 4, 0, 20};
    int k2 = 4;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    findPairsWithDiff(arr2, n2, k2);
    return 0;
}
