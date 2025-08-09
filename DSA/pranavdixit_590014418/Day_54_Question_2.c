#include <stdio.h>

int maxArea(int* height, int n) {
    int max = 0, left = 0, right = n - 1;

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int area = h * (right - left);
        if (area > max)
            max = area;

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return max;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(height) / sizeof(height[0]);

    printf("Max area: %d\n", maxArea(height, n));  // Output: 49
    return 0;
}
