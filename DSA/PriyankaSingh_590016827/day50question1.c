#include <stdio.h>

int main() {
    int arr[100], n, k, i, max_sum = 0, window_sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter value of k: ");
    scanf("%d", &k);

    for(i = 0; i < k; i++)
        window_sum += arr[i];
    
    max_sum = window_sum;

    for(i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        if(window_sum > max_sum)
            max_sum = window_sum;
    }

    printf("Maximum sum of subarray of size %d: %d\n", k, max_sum);
    return 0;
}
