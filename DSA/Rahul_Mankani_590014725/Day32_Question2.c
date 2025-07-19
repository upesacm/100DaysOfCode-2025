#include <stdio.h>

int uni(int arr[], int size) 
{
    int result = 0;
    for (int i = 0; i < size; i++) 
    {
        result ^= arr[i]; // XOR all elements
    }
    return result;
}
int main() 
{
    int n;
    printf("Enter array size (odd number): ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d numbers (all appear twice except one): ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int unique = uni(arr, n);
    printf("The non-repeating element is: %d\n", unique);
    return 0;
}
