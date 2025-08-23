#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (n <= 1) { printf("0\n"); return 0; }
    if (arr[0] == 0) { printf("-1\n"); return 0; }

    int jumps = 0, currEnd = 0, maxReach = 0;
    for (int i = 0; i < n - 1; i++) {
        if (i + arr[i] > maxReach) maxReach = i + arr[i];
        if (i == currEnd) {
            jumps++;
            currEnd = maxReach;
            if (currEnd >= n - 1) break;
        }
        if (i >= maxReach) { printf("-1\n"); return 0; }
    }

    printf("%d\n", jumps);
    return 0;
}
