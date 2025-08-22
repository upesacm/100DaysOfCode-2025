#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    printf("Enter target sum: ");
    scanf("%d", &target);

    qsort(nums, n, sizeof(int), compare);
    printf("Triplets:\n");
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                printf("[%d, %d, %d]\n", nums[i], nums[left], nums[right]);
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            } else if (sum < target) left++;
            else right--;
        }
    }
    return 0;
}
