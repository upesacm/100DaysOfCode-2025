#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int height[n];
    printf("Enter heights:\n");
    for (int i = 0; i < n; i++) scanf("%d", &height[i]);

    int left = 0, right = n - 1, maxArea = 0;
    while (left < right) {
        int h = (height[left] < height[right]) ? height[left] : height[right];
        int width = right - left;
        int area = h * width;
        if (area > maxArea) maxArea = area;

        if (height[left] < height[right]) left++;
        else right--;
    }

    printf("Maximum water container area: %d\n", maxArea);
    return 0;
}
