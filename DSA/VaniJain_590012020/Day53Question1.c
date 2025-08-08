#include <stdio.h>
int main() 
{
    int n;
    printf("Enter the number of elements in the binary array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d binary elements (0 or 1): ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int currentCount = 0, maxCount = 0;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == 1) 
        {
            currentCount++;
            if (currentCount > maxCount) 
            {
                maxCount = currentCount;
            }
        } 
        else 
        {
            currentCount = 0; 
        }
    }
    printf("Maximum number of consecutive 1s: %d\n", maxCount);
    return 0;
}
