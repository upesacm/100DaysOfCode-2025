#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int largestRectangleArea(int* heights, int n) {
    int* stack = (int*)malloc((n + 1) * sizeof(int));
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int currHeight = (i == n) ? 0 : heights[i]; 

        while (top != -1 && currHeight < heights[stack[top]]) {
            int height = heights[stack[top--]];

            int width;
            if (top == -1)
                width = i;
            else
                width = i - stack[top] - 1;

            int area = height * width;
            maxArea = max(maxArea, area);
        }
        stack[++top] = i;
    }

    free(stack);
    return maxArea;
}

int main() {
    int heights[] = {2,4};
    int n = sizeof(heights) / sizeof(heights[0]);

    int result = largestRectangleArea(heights, n);
    printf("Maximum rectangle area is %d\n", result);

    return 0;
}
