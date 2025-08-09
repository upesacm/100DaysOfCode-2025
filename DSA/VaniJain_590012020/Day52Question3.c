#include <stdio.h>
int main() 
{
    int n;
    printf("Enter the number of bars: ");
    scanf("%d", &n);
    int height[n];
    printf("Enter the heights of the bars: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &height[i]);
    }
    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int water = 0;
    while (left < right) 
    {
        if (height[left] < height[right]) 
        {
            if (height[left] >= left_max) 
            {
                left_max = height[left];
            } 
            else 
            {
                water += left_max - height[left];
            }
            left++;
        } 
        else 
        {
            if (height[right] >= right_max) 
            {
                right_max = height[right];
            } 
            else 
            {
                water += right_max - height[right];
            }
            right--;
        }
    }
    printf("Total trapped water: %d units\n", water);
    return 0;
}
