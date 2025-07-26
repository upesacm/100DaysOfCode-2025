#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int max(int a, int b) {
    return (a > b) ? a : b;
}
int largestRectangleArea(int heights[], int n) 
{
    int stack[MAX];
    int top = -1;
    int maxArea = 0;
    int i = 0;
    while (i < n) 
    {
        if (top == -1 || heights[i] >= heights[stack[top]]) 
        {
            stack[++top] = i++;
        } else 
        {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            maxArea = max(maxArea, area);
        }
    }
    while (top != -1) 
    {
        int height = heights[stack[top--]];
        int width = (top == -1) ? i : i - stack[top] - 1;
        int area = height * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}
int main() 
{
    int n;
    printf("Enter number of histogram bars: ");
    scanf("%d", &n);
    int *heights = (int *)malloc(n * sizeof(int));
    printf("Enter heights of histogram bars:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &heights[i]);
    }
    int maxArea = largestRectangleArea(heights, n);
    printf("The largest rectangle area is: %d\n", maxArea);
    free(heights);
    return 0;
}
