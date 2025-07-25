#include <stdio.h>

int largestRectangleArea(int* heights, int n) {
    int stack[n + 1], top = -1;
    int maxArea = 0, i = 0;

    while (i <= n) {
        int h = (i == n) ? 0 : heights[i];
        if (top == -1 || h >= heights[stack[top]]) {
            stack[++top] = i++;
        } else {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            if (area > maxArea)
                maxArea = area;
        }
    }
    return maxArea;
}


int main() {
    int heights1[] = {2, 1, 5, 6, 2, 3};
    int heights2[] = {2, 4};

    printf("Max Area: %d\n", largestRectangleArea(heights1, 6)); 
    printf("Max Area: %d\n", largestRectangleArea(heights2, 2)); 

    return 0;
}

