#include <stdio.h>
#include <stdbool.h>

bool hasPairWithSum(int arr[], int n, int x) {
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
    int arr[] = {1, 4, 6, 8, 10, 45};
    int x = 16;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (hasPairWithSum(arr, n, x))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}

