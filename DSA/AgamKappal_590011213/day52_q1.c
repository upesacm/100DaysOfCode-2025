
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool hasPairWithSum(int arr[], int n, int x) {
    qsort(arr, n, sizeof(int), compare);
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == x)
            return true;
        else if (sum < x)
            left++;
        else
            right--;
    }
    return false;
}

int main() {
    int arr[] = {1, 4, 45, 6, 10, 8};
    int x = 16;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (hasPairWithSum(arr, n, x))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
