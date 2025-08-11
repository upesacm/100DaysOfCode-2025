#include <stdio.h>
#include <stdlib.h>

int Subarrays_Sum(int nums[], int n, int goal) {
    int maxPossibleSum = n;
    int* prefixCount = (int*)calloc(maxPossibleSum + 1, sizeof(int));
    if (prefixCount == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }
    
    int count = 0;
    int currentSum = 0;
    
    prefixCount[0] = 1;
    
    for (int i = 0; i < n; i++) {
        currentSum += nums[i];
        
        if (currentSum >= goal && currentSum - goal <= maxPossibleSum) {
            count += prefixCount[currentSum - goal];
        }
        
        if (currentSum <= maxPossibleSum) {
            prefixCount[currentSum]++;
        }
    }
    
    free(prefixCount);
    return count;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int* nums = (int*)malloc(n * sizeof(int));
    if (nums == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter the elements of the array (binary, 0 or 1, space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        if (nums[i] != 0 && nums[i] != 1) {
            printf("Invalid input. Only 0 and 1 are allowed.\n");
            free(nums);
            return 1;
        }
    }
    
    int goal;
    printf("Enter the goal sum: ");
    scanf("%d", &goal);
    
    int result = Subarrays_Sum(nums, n, goal);
    if (result != -1) {
        printf("Number of subarrays with sum %d: %d\n", goal, result);
    }
    
    free(nums);
    return 0;
}
