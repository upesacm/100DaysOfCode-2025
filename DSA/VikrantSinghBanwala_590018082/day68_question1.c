#include <stdio.h>

int minJumps(int arr[], int n) {
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;

    int jumps = 0, currentEnd = 0, farthest = 0;

    for (int i = 0; i < n - 1; i++) {
        farthest = (i + arr[i] > farthest) ? i + arr[i] : farthest;

        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;

            if (currentEnd >= n - 1) break;
        }
    }

    return jumps;
}

int main() {
    int arr1[] = {2, 3, 1, 1, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n", minJumps(arr1, n1));

    int arr2[] = {1, 1, 1, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", minJumps(arr2, n2));

    return 0;
}
