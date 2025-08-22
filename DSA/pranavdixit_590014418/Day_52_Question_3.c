#include <stdio.h>

int trapRainWater(int height[], int n) {
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];
            left++;
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];
            right--;
        }
    }

    return water;
}

int main() {
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(height) / sizeof(height[0]);

    int result = trapRainWater(height, n);
    printf("Trapped water: %d\n", result);  // Output: 6

    return 0;
}
