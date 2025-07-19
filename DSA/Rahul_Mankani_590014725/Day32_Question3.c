#include <stdio.h>

int XOR(int arr[], int size) 
{
    int result = 0;
    for (int i = 0; i < size; i++) 
    {
        result ^= arr[i]; // XOR each element
    }
    return result;
}
int main() 
{
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int result = XOR(arr, n);
    printf("XOR of all elements: %d\n", xor_result);
    return 0;
}
