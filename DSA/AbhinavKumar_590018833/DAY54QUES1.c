// 1. Three Sum Problem
// A problem that introduces multi-pointer optimization techniques and teaches triplet finding algorithms using sorted array traversal methods for advanced sum-based analysis and combinatorial operations.

// Find all triplets in an array that sum up to a given target (e.g., 0) using three-pointer technique with duplicate handling. This operation is fundamental in combinatorial optimization and multi-element analysis where you need to find complex relationships between multiple array elements efficiently. The technique uses sorted array traversal with fixed first element and two-pointer search for remaining pairs, avoiding duplicate triplets through careful advancement. This concept is essential in algorithmic problem solving, financial analysis, and optimization problems where finding multi-element combinations that meet specific criteria enables complex decision making and relationship analysis.

// This teaches multi-pointer algorithms and combinatorial optimization techniques that are essential for triplet finding and efficient multi-element relationship analysis operations.

// Your task: Implement three-pointer technique with duplicate avoidance to find all unique triplets meeting target sum criteria efficiently.

// Examples
// Input:

// nums = [-1, 0, 1, 2, -1, -4]
// Output:

// [[-1, -1, 2], [-1, 0, 1]]
// Input:

// nums = [0,1,1]
// Output:

// []

#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b){
    return (*(int*)a-*(int*)b);

}
void threeSum(int nums[], int n) {
    if (n < 3) {
        printf("[]\n");
        return;
    }
    qsort(nums, n, sizeof(int), compare);
    
    printf("[");
    int found_count = 0;

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = n - 1;
        int target = -nums[i];

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                if (found_count > 0) printf(", ");
                printf("[%d, %d, %d]", nums[i], nums[left], nums[right]);
                found_count++;

                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    printf("]\n");
}
int main(){
    int nums1[]={-1,0,1,2,-1,-4};
    int n1=sizeof(int)/sizeof(nums1[0]);
    printf("INPUT: {-1,0,1,2,-1,4}\n");
    printf("OUTPUT:");
    threeSum(nums1,n1);
    return 0;
}