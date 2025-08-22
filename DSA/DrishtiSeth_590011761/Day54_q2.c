#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int max = 0;
    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int area = h * (right - left);
        if (area > max) max = area;
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return max;
}

int main() {
    int height[] = {1,8,6,2,5,4,8,3,7};
    int size = sizeof(height) / sizeof(height[0]);
    printf("%d\n", maxArea(height, size));
    return 0;
}