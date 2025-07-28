#include <stdio.h>

int largestRectangleArea(int heights[], int n) {
    int stack[100], top = -1;
    int maxArea = 0, i = 0;

    while (i < n) {
        if (top == -1 || heights[stack[top]] <= heights[i])
            stack[++top] = i++;
        else {
            int h = heights[stack[top--]];
            int width = top == -1 ? i : i - stack[top] - 1;
            int area = h * width;
            if (area > maxArea) maxArea = area;
        }
    }

    while (top != -1) {
        int h = heights[stack[top--]];
        int width = top == -1 ? i : i - stack[top] - 1;
        int area = h * width;
        if (area > maxArea) maxArea = area;
    }

    return maxArea;
}

int main() {
    int n;
    scanf("%d", &n);
    int heights[100];
    for (int i = 0; i < n; i++) scanf("%d", &heights[i]);
    printf("%d\n", largestRectangleArea(heights, n));
    return 0;
}
