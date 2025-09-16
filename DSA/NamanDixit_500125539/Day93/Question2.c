#include <stdio.h>

int maxSubArray(int arr[], int n) {
    int current_sum = arr[0];
    int max_sum = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > current_sum + arr[i])
            current_sum = arr[i];
        else
            current_sum = current_sum + arr[i];

        if (current_sum > max_sum)
            max_sum = current_sum;
    }
    return max_sum;
}

int main() {
    int arr1[] = {-2,1,-3,4,-1,2,1,-5,4};
    int arr2[] = {1};

    printf("Max subarray sum (case 1): %d\n", maxSubArray(arr1, 9));
    printf("Max subarray sum (case 2): %d\n", maxSubArray(arr2, 1));

    return 0;
}
