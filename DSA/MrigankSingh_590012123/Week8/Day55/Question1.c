#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    long long sum;
    int index;
} HashEntry;

int longest_Subarray_Sum(int arr[], int n, int k) {
    HashEntry* hashMap = (HashEntry*)calloc(2 * 1000000 + 1, sizeof(HashEntry));
    if (hashMap == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }
    
    long long currentSum = 0;
    int maxLength = 0;
    
    hashMap[1000000].sum = 0;
    hashMap[1000000].index = -1;
    
    for (int i = 0; i < n; i++) {
        currentSum += arr[i];
        
        long long targetSum = currentSum - k;
        int targetIndex = targetSum + 1000000;
        if (targetIndex >= 0 && targetIndex < 2 * 1000000 + 1 && hashMap[targetIndex].index != -1) {
            int currentLength = i - hashMap[targetIndex].index;
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        }
        
        int sumIndex = currentSum + 1000000;
        if (sumIndex >= 0 && sumIndex < 2 * 1000000 + 1 && hashMap[sumIndex].index == -1) {
            hashMap[sumIndex].sum = currentSum;
            hashMap[sumIndex].index = i;
        }
    }
    
    free(hashMap);
    return maxLength;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter the elements of the array (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    
    int result = longest_Subarray_Sum(arr, n, k);
    if (result != -1) {
        printf("Length of the longest subarray with sum %d: %d\n", k, result);
    }
    
    free(arr);
    return 0;
}
