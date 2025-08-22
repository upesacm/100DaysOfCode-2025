#include <stdio.h>
#include <stdlib.h>

int Subarray_Product_lessthan_K(int nums[], int n, int k) {
    if (k <= 1) {
        return 0;
    }
    
    int count = 0;
    long long product = 1; 
    int start = 0;
    
    for (int end = 0; end < n; end++) {
        product *= nums[end]; 
        
        while (product >= k && start <= end) {
            product /= nums[start];
            start++;
        }
        
        count += (end - start + 1);
    }
    
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
    
    printf("Enter the elements of the array (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    
    int result = Subarray_Product_lessthan_K(nums, n, k);
    printf("Number of subarrays with product less than %d: %d\n", k, result);
    
    free(nums);
    return 0;
}
