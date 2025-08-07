#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}


int trapRainWater(int height[], int n) {
    if (n < 3) {
        return 0;
    }

    int left = 0;
    int right = n - 1;
    int left_max = 0;
    int right_max = 0;
    int total_water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            left_max = max(left_max, height[left]);
            total_water += left_max - height[left];
            left++;
        } else {
            right_max = max(right_max, height[right]);
            total_water += right_max - height[right];
            right--;
        }
    }
    return total_water;
}

int main() {
    main_pairs();
    printf("\n----------------------------------\n\n");

    
    int height1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n1 = sizeof(height1) / sizeof(height1[0]);
    printf("Input: height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}\n");
    printf("Output: %d\n\n", trapRainWater(height1, n1));

    int height2[] = {4, 2, 0, 3, 2, 5};
    int n2 = sizeof(height2) / sizeof(height2[0]);
    printf("Input: height = {4, 2, 0, 3, 2, 5}\n");
    printf("Output: %d\n", trapRainWater(height2, n2));

    return 0;
}