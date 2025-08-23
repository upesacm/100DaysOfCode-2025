#include <stdio.h>
#include <limits.h>

int minJumps(int arr[], int n) {
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;
    int maxReach = arr[0], step = arr[0], jump = 1;
    for (int i = 1; i < n; i++) {
        if (i == n - 1) return jump;
        if (i + arr[i] > maxReach) maxReach = i + arr[i];
        step--;
        if (step == 0) {
            jump++;
            if (i >= maxReach) return -1;
            step = maxReach - i;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int result = minJumps(arr, n);
    if (result == -1)
        printf("End cannot be reached\n");
    else
        printf("Minimum jumps required: %d\n", result);
    return 0;
}
