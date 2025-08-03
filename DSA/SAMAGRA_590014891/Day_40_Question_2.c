#include <stdio.h>

int largestRectangleArea(int* h, int n) {
    int stack[n + 1], top = -1, max_area = 0;
    h[n] = 0;
    for (int i = 0; i <= n; i++) {
        while (top != -1 && h[stack[top]] > h[i]) {
            int height = h[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            if (area > max_area) max_area = area;
        }
        stack[++top] = i;
    }
    return max_area;
}

int main() {
    int n, h[10001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
    printf("%d\n", largestRectangleArea(h, n));
    return 0;
}
