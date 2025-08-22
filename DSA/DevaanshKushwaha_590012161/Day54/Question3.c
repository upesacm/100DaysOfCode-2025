#include <stdio.h>
int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    printf("Enter k: ");
    scanf("%d", &k);
    long long prod = 1;
    int left = 0, count = 0;
    for (int right = 0; right < n; right++) {
        prod *= nums[right];
        while (left <= right && prod >= k) {
            prod /= nums[left];
            left++;
        }
        count += right - left + 1;
    }
    printf("Number of subarrays: %d", count);
}
