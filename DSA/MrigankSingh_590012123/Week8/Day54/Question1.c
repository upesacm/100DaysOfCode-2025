#include <stdio.h>
#include <stdlib.h>

typedef struct Triplet {
    int first;
    int second;
    int third;
} Triplet;

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

Triplet* findThreeSum(int nums[], int n, int target, int* tripletCount) {
    Triplet* triplets = (Triplet*)malloc(n * n * sizeof(Triplet)); 
    *tripletCount = 0;
    
    qsort(nums, n, sizeof(int), compare);
    
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];
            
            if (currentSum == target) {
                triplets[*tripletCount].first = nums[i];
                triplets[*tripletCount].second = nums[left];
                triplets[*tripletCount].third = nums[right];
                (*tripletCount)++;
                
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                left++;
                right--;
            } else if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return triplets;
}

void printTriplets(Triplet* triplets, int tripletCount) {
    printf("[");
    for (int i = 0; i < tripletCount; i++) {
        printf("[%d, %d, %d]", triplets[i].first, triplets[i].second, triplets[i].third);
        if (i < tripletCount - 1) {
            printf(", ");
        }
    }
    printf("]\n");
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
    
    printf("Enter the elements of the array (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    int target;
    printf("Enter the target sum: ");
    scanf("%d", &target);
    
    int tripletCount;
    Triplet* triplets = findThreeSum(nums, n, target, &tripletCount);
    
    printf("Unique triplets that sum to %d:\n", target);
    printTriplets(triplets, tripletCount);
    
    free(triplets);
    free(nums);
    
    return 0;
}
