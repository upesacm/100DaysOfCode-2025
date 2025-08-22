#include <stdio.h>
#include <stdlib.h>

int maxArea(int height[], int n) {
    int maxWater = 0;
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        int width = right - left;
        int minHeight = height[left] < height[right] ? height[left] : height[right];
        int currentArea = width * minHeight;
        
        if (currentArea > maxWater) {
            maxWater = currentArea;
        }
        
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return maxWater;
}

int main() {
    int n;
    printf("Enter the number of heights: ");
    scanf("%d", &n);
    
    int* height = (int*)malloc(n * sizeof(int));
    if (height == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter the heights (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }
    
    int result = maxArea(height, n);
    printf("Maximum water container area: %d\n", result);
    
    free(height);
    return 0;
}
