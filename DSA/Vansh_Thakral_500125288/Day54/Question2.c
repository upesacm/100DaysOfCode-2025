#include <stdio.h>

int maxArea(int* height, int n) {
    int left = 0, right = n - 1, maxArea = 0;

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int w = right - left;
        int area = h * w;

        if (area > maxArea)
            maxArea = area;

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxArea;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(height) / sizeof(height[0]);

    printf("%d\n", maxArea(height, n)); 
    return 0;
}

