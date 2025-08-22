#include <stdio.h>
int maxArea(int height[], int n) 
{
    int left = 0;
    int right = n - 1;
    int max_area = 0;
    while (left < right) 
    {
        int width = right - left;
        int h = (height[left] < height[right]) ? height[left] : height[right];
        int area = width * h;
        if (area > max_area) 
        {
            max_area = area;
        }
        if (height[left] < height[right]) 
        {
            left++;
        } 
        else 
        {
            right--;
        }
    }
    return max_area;
}
int main() 
{
    int n;
    printf("Enter the number of heights: ");
    scanf("%d", &n);
    int height[n];
    printf("Enter the heights:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &height[i]);
    }
    int result = maxArea(height, n);
    printf("Maximum water that can be contained: %d\n", result);
    return 0;
}
