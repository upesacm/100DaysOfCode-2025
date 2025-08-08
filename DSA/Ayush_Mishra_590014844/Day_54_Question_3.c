#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int count = 0, left = 0;
    long long prod = 1;
    for (int right = 0; right < n; right++) {
        prod *= nums[right];
        while (left <= right && prod >= k) {
            prod /= nums[left];
            left++;
        }
        count += right - left + 1;
    }

    printf("%d\n", count);
    return 0;
}
