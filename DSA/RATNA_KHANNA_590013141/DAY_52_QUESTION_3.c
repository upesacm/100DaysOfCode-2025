#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("enter number of array elements\n");
    scanf("%d", &n);
    int *height = (int *)malloc(n * sizeof(int));
     printf("enter the elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &height[i]);
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
    printf("output-%d\n", water);
    free(height);
    return 0;
}
