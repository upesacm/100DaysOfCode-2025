#include <stdio.h>

#define MAX 1000

int max(int a, int b) {
    return a > b ? a : b;
}

int largestRectangleArea(int heights[], int n) {
    int stack[MAX], top = -1;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int currHeight = (i == n) ? 0 : heights[i]; 
        while (top != -1 && currHeight < heights[stack[top]]) {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            maxArea = max(maxArea, area);
        }

        stack[++top] = i;
    }

    return maxArea;
}

int main() {
    int n, heights[MAX];

    printf("Enter number of histogram bars: ");
    scanf("%d", &n);

    printf("Enter heights of histogram bars:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    int result = largestRectangleArea(heights, n);
    printf("Largest rectangle area: %d\n", result);

    return 0;
}
