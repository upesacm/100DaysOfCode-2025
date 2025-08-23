#include <stdio.h>

int minJumps(int arr[], int n) {
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1; // cannot move

    int jumps = 1, maxReach = arr[0], steps = arr[0];
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
    int arr1[] = {2,3,1,1,4};
    printf("Min jumps: %d\n", minJumps(arr1, 5)); // 2

    int arr2[] = {1,1,1,1};
    printf("Min jumps: %d\n", minJumps(arr2, 4)); // 3
    return 0;
}
