#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int maxArea = 0;

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int width = right - left;
        int area = h * width;
        if (area > maxArea) maxArea = area;

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxArea;
}

int main() {
    int height[] = {1,8,6,2,5,4,8,3,7};
    int n = sizeof(height) / sizeof(height[0]);
    printf("%d\n", maxArea(height, n));
    return 0;
}
