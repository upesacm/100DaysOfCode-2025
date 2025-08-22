#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void threeSum(int* nums, int n) {
    qsort(nums, n, sizeof(int), compare);

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue; 

        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                printf("[%d, %d, %d]\n", nums[i], nums[left], nums[right]);

              
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int n = sizeof(nums) / sizeof(nums[0]);

    threeSum(nums, n);
    return 0;
}

