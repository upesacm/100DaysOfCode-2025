#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int height[n];
    printf("Enter heights: ");
    for (int i = 0; i < n; i++) scanf("%d", &height[i]);
    int l = 0, r = n - 1, maxArea = 0;
    while (l < r) {
        int h = height[l] < height[r] ? height[l] : height[r];
        int area = h * (r - l);
        if (area > maxArea) maxArea = area;
        if (height[l] < height[r]) l++;
        else r--;
    }
    printf("Maximum water area: %d", maxArea);
}
