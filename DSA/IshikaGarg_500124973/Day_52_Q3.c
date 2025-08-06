#include <stdio.h>

// Function to calculate trapped rainwater using two-pointer technique
int trap(int* height, int n) {
    if (n <= 2) return 0;

    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= left_max)
                left_max = height[left];
            else
                water += left_max - height[left];
            left++;
        } else {
            if (height[right] >= right_max)
                right_max = height[right];
            else
                water += right_max - height[right];
            right--;
        }
    }
    return water;
}

// Driver code
int main() {
    int height1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n1 = sizeof(height1) / sizeof(height1[0]);
    printf("Trapped Water = %d\n", trap(height1, n1)); // Output: 6

    int height2[] = {4, 2, 0, 3, 2, 5};
    int n2 = sizeof(height2) / sizeof(height2[0]);
    printf("Trapped Water = %d\n", trap(height2, n2)); // Output: 9

    return 0;
}

