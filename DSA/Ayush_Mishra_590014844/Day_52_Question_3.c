#include <stdio.h>

int trapRainWater(int height[], int n) {
    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0, water = 0;
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

int main() {
    int n;
    printf("Enter number of elevation points: ");
    scanf("%d", &n);
    int height[n];
    printf("Enter elevation map: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &height[i]);
    int result = trapRainWater(height, n);
    printf("Trapped water: %d\n", result);
    return 0;
}
