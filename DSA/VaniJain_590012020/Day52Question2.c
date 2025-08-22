#include <stdio.h>
int main() 
{
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the difference value k: ");
    scanf("%d", &k);
    int hash[100001] = {0};
    for (int i = 0; i < n; i++) 
    {
        hash[arr[i]] = 1;
    }
    printf("Pairs with difference %d:\n", k);
    int found = 0;
    for (int i = 0; i < n; i++) 
    {
        if ((arr[i] + k) >= 0 && (arr[i] + k) <= 100000 && hash[arr[i] + k]) 
        {
            printf("(%d, %d)\n", arr[i], arr[i] + k);
            found = 1;
        }
    }
    if (!found) 
    {
        printf("No such pairs found.\n");
    }
    return 0;
}
