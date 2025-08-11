#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int height[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    int left = 0, right = n - 1, max_area = 0;
    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int area = h * (right - left);
        if (area > max_area) max_area = area;
        if (height[left] < height[right]) left++;
        else right--;
    }

    printf("%d\n", max_area);
    return 0;
}
