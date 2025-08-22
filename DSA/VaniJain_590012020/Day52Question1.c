#include <stdio.h>
int main() 
{
    int n, x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target sum x: ");
    scanf("%d", &x);
    int left = 0, right = n - 1;
    int found = 0;
    while (left < right) 
    {
        int sum = arr[left] + arr[right];
        if (sum == x) 
        {
            printf("Pair found: (%d, %d)\n", arr[left], arr[right]);
            found = 1;
            break;
        }
        else if (sum < x) 
        {
            left++;
        }
        else 
        {
            right--;
        }
    }
    if (!found) 
    {
        printf("No such pair exists.\n");
    }
    return 0;
}
