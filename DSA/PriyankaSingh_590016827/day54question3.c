#include <stdio.h>

int main() {
    int n;
    long long k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    printf("Enter k: ");
    scanf("%lld", &k);

    if (k <= 1) {
        printf("Number of subarrays: 0\n");
        return 0;
    }

    long long prod = 1, count = 0;
    int left = 0;
    for (int right = 0; right < n; right++) {
        prod *= nums[right];
        while (prod >= k) {
            prod /= nums[left];
            left++;
        }
        count += (right - left + 1);
    }

    printf("Number of subarrays: %lld\n", count);
    return 0;
}
