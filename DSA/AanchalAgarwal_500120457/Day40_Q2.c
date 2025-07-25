#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int largestRectangleArea(int* heights, int n) {
    int stack[MAX];
    int top = -1;
    int maxArea = 0;

    // Append 0 to force stack emptying at end
    heights[n] = 0;
    n++;

    for (int i = 0; i < n; i++) {
        // Keep stack in increasing order
        while (top != -1 && heights[i] < heights[stack[top]]) {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            if (area > maxArea)
                maxArea = area;
        }
        stack[++top] = i;
    }

    return maxArea;
}
