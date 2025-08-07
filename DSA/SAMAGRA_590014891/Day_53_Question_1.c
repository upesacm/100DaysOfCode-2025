#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int maxCount = 0, count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            count++;
            if (count > maxCount) maxCount = count;
        } else {
            count = 0;
        }
    }
    return maxCount;
}
