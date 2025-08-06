#include <stdio.h>
int trap(int height[], int n) {
    if (n <= 2) return 0;
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int waterTrapped = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                waterTrapped += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                waterTrapped += rightMax - height[right];
            }
            right--;
        }
    }
    return waterTrapped;
}
int main() {
    int height1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n1 = sizeof(height1) / sizeof(height1[0]);
    printf("%d\n", trap(height1, n1));
    int height2[] = {4, 2, 0, 3, 2, 5};
    int n2 = sizeof(height2) / sizeof(height2[0]);
    printf("%d\n", trap(height2, n2));
    return 0;
}