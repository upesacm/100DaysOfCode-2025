#include <stdio.h>
#include <limits.h>

int minJumps(int arr[], int n) {
    if (n <= 1) return 0;         // Already at end
    if (arr[0] == 0) return -1;   // Can't move anywhere

    int jumps = 1;        // At least one jump needed
    int maxReach = arr[0]; // Farthest reachable index
    int steps = arr[0];   // Steps left in current jump range

    for (int i = 1; i < n; i++) {
        if (i == n - 1) return jumps; // Reached end

        maxReach = (i + arr[i] > maxReach) ? i + arr[i] : maxReach;
        steps--;

        if (steps == 0) {
            jumps++;
            if (i >= maxReach) return -1; // Cannot move further
            steps = maxReach - i;
        }
    }
    return -1;
}

int main() {
    int arr1[] = {2, 3, 1, 1, 4};
    int arr2[] = {1, 1, 1, 1};
    printf("Min Jumps: %d\n", minJumps(arr1, 5)); // Output: 2
    printf("Min Jumps: %d\n", minJumps(arr2, 4)); // Output: 3
    return 0;
}

