#include <stdio.h>

int main() {
    int n, k;
    printf("enter number of elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter elements\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("enter value of k\n");
    scanf("%d", &k);

    int sum = 0;
    for(int i = 0; i < k; i++)
        sum += arr[i];
    int max_sum = sum;

    for(int i = k; i < n; i++) {
        sum = sum - arr[i - k] + arr[i];
        if(sum > max_sum)
            max_sum = sum;
    }

    printf(" Maximum Sum Subarray of Size K%d", max_sum);
    return 0;
}
