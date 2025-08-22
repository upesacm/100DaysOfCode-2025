#include <stdio.h>
int main() 
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int longest = 0;
    int i = 1;
    while (i < n - 1) 
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) 
        {
            int left = i - 1;
            int right = i + 1;
            while (left > 0 && arr[left] > arr[left - 1]) 
            {
                left--;
            }
            while (right < n - 1 && arr[right] > arr[right + 1]) 
            {
                right++;
            }
            int length = right - left + 1;
            if (length > longest) 
            {
                longest = length;
            }
            i = right;
        }
        else 
        {
            i++;
        }
    }
    if (longest >= 3) 
    {
        printf("Length of the longest mountain: %d\n", longest);
    }
    else 
    {
        printf("No mountain found.\n");
    }
    return 0;
}
