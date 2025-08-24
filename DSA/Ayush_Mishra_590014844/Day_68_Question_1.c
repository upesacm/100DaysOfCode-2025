#include <stdio.h>

int minJumps(int arr[], int n) {
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;

    int maxReach = arr[0], steps = arr[0], jumps = 1;
    for (int i = 1; i < n; i++) {
        if (i == n - 1) return jumps;
        maxReach = (i + arr[i] > maxReach) ? i + arr[i] : maxReach;
        steps--;
        if (steps == 0) {
            jumps++;
            if (i >= maxReach) return -1;
            steps = maxReach - i;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int result = minJumps(arr, n);
    printf("Minimum jumps: %d\n", result);
    return 0;
}
