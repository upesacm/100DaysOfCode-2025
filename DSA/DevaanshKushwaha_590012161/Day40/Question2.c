#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int* heights = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;
    int max_area = 0;
    int i = 0;

    while (i < n) {
        if (top == -1 || heights[stack[top]] <= heights[i]) {
            stack[++top] = i++;
        } else {
            int h = heights[stack[top--]];
            int w = (top == -1) ? i : i - stack[top] - 1;
            if (h * w > max_area) {
                max_area = h * w;
            }
        }
    }

    while (top != -1) {
        int h = heights[stack[top--]];
        int w = (top == -1) ? i : i - stack[top] - 1;
        if (h * w > max_area) {
            max_area = h * w;
        }
    }

    printf("%d\n", max_area);

    free(heights);
    free(stack);

    return 0;
}
