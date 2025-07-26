#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int largestRectangleArea(int* heights, int n) {
    int* stack = (int*)malloc(sizeof(int) * (n + 1));
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int currentHeight = (i == n) ? 0 : heights[i];

        while (top != -1 && heights[stack[top]] > currentHeight) {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            maxArea = max(maxArea, height * width);
        }

        stack[++top] = i;
    }

    free(stack);
    return maxArea;
}

int main() {
    int n;
    printf("Enter the number of histogram bars: ");
    scanf("%d", &n);

    int* heights = (int*)malloc(sizeof(int) * n);

    printf("Enter the heights of histogram bars:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    int result = largestRectangleArea(heights, n);
    printf("Largest rectangle area is: %d\n", result);

    free(heights);
    return 0;
}
