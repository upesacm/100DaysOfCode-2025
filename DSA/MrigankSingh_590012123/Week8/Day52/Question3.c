#include <stdio.h>
#include <stdlib.h>

int trap_rainwater(int height[], int n) {
    if (n <= 2) {
        return 0;
    }

    int left = 0;
    int right = n - 1;
    int leftMax = 0;
    int rightMax = 0;
    int water = 0;

    while (left < right) {
        if (height[left] > leftMax) {
            leftMax = height[left];
        }
        if (height[right] > rightMax) {
            rightMax = height[right];
        }

        if (leftMax <= rightMax) {
            water += leftMax - height[left];
            left++;
        } else {
            water += rightMax - height[right];
            right--;
        }
    }

    return water;
}

int main() {
    int n;

    printf("Enter the number of elevation bars: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Output: 0\n");
        return 0;
    }

    int* height = (int*)malloc(n * sizeof(int));
    printf("Enter the heights of the bars:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    int result = trap_rainwater(height, n);
    printf("Output: %d\n", result);

    free(height);
    return 0;
}
