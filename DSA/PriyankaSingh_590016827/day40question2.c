
#include <stdio.h>

#define MAX 100

int main() {
    int heights[MAX], stack[MAX];
    int n, top = -1, maxArea = 0, area = 0;

    printf("Enter number of bars: ");
    scanf("%d", &n);
    printf("Enter heights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &heights[i]);

    int i = 0;
    while (i < n) {
        if (top == -1 || heights[i] >= heights[stack[top]]) {
            stack[++top] = i++;
        } else {
            int h = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            area = h * width;
            if (area > maxArea) maxArea = area;
        }
    }

    while (top != -1) {
        int h = heights[stack[top--]];
        int width = (top == -1) ? i : i - stack[top] - 1;
        area = h * width;
        if (area > maxArea) maxArea = area;
    }

    printf("Max Area: %d\n", maxArea);
    return 0;
}
