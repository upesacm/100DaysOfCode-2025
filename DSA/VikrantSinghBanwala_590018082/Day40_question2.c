#include <stdio.h>

#define MAX 100

int maxArea(int heights[], int n) {
    int stack[MAX], top = -1;
    int max = 0, i = 0;

    while (i < n) {
        if (top == -1 || heights[i] >= heights[stack[top]])
            stack[++top] = i++;
        else {
            int h = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = h * width;
            if (area > max) max = area;
        }
    }

    while (top != -1) {
        int h = heights[stack[top--]];
        int width = (top == -1) ? i : i - stack[top] - 1;
        int area = h * width;
        if (area > max) max = area;
    }

    return max;
}

int main() {
    int heights[] = {2, 1, 5, 6, 2, 3};
    int n = sizeof(heights) / sizeof(heights[0]);

    int result = maxArea(heights, n);
    printf("%d\n", result);
    return 0;
}
