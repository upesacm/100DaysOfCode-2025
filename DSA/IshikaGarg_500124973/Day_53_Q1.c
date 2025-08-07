#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int maxCount = 0, currentCount = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        } else {
            currentCount = 0;
        }
    }
    return maxCount;
}

int main() {
    int nums[] = {1, 1, 0, 1, 1, 1};
    int size = sizeof(nums)/sizeof(nums[0]);
    printf("Max Consecutive Ones: %d\n", findMaxConsecutiveOnes(nums, size));
    return 0;
}

