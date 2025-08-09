#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    printf("Enter target sum: ");
    scanf("%d", &target);
    qsort(nums, n, sizeof(int), cmp);
    printf("[");
    int firstPrinted = 0;
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == target) {
                if (firstPrinted) printf(", ");
                printf("[%d, %d, %d]", nums[i], nums[l], nums[r]);
                firstPrinted = 1;
                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;
                l++;
                r--;
            } else if (sum < target) l++;
            else r--;
        }
    }
    printf("]");
}
