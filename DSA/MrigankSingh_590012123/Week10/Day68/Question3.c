#include <stdio.h>
#include <stdlib.h>

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

int maxSumAfterKNegations(int nums[], int n, int k) {
    // Build min heap
    buildMinHeap(nums, n);
    
    // Perform k negations
    while (k > 0) {
        // Negate the smallest element
        nums[0] = -nums[0];
        // Heapify to maintain heap property
        minHeapify(nums, n, 0);
        k--;
    }
    
    // Calculate sum
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }
    
    return sum;
}

int main() {
    int n, k;
    printf("Enter array size: ");
    scanf("%d", &n);
    
    int nums[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    printf("Enter number of negations (k): ");
    scanf("%d", &k);
    
    int result = maxSumAfterKNegations(nums, n, k);
    printf("Maximum sum after %d negations: %d\n", k, result);
    
    return 0;
}
