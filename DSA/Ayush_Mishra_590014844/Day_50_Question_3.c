#include <stdio.h>

int main() {
    int n, target;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &target);

    int start = 0, sum = 0, found = 0;
    for (int end = 0; end < n; end++) {
        sum += arr[end];
        while (sum > target && start < end)
            sum -= arr[start++];

        if (sum == target) {
            printf("Subarray found from index %d to %d\n", start, end);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No subarray found\n");

    return 0;
}
