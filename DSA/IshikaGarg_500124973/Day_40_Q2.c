#include <stdio.h>

int getMaxArea(int hist[], int n) {
    int stack[n];
    int top = -1;
    int maxArea = 0, area, i = 0;

    while (i < n) {
        if (top == -1 || hist[i] >= hist[stack[top]]) {
            stack[++top] = i++;
        } else {
            int tp = stack[top--];
            int width = (top == -1) ? i : i - stack[top] - 1;
            area = hist[tp] * width;
            if (area > maxArea)
                maxArea = area;
        }
    }

    while (top != -1) {
        int tp = stack[top--];
        int width = (top == -1) ? i : i - stack[top] - 1;
        area = hist[tp] * width;
        if (area > maxArea)
            maxArea = area;
    }

    return maxArea;
}

int main() {
    int hist[] = {2, 1, 5, 6, 2, 3};
    int n = sizeof(hist) / sizeof(hist[0]);

    int maxArea = getMaxArea(hist, n);
    printf("Max Area: %d\n", maxArea); // Output: 10

    return 0;
}

