#include <stdio.h>

int hasPairWithSum(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == x)
            return 1;
        else if (sum < x)
            left++;
        else
            right--;
    }
    return 0;
}

int main() {
    int n, x;
    printf("Enter size of sorted array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter sorted array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter target sum: ");
    scanf("%d", &x);
    if (hasPairWithSum(arr, n, x))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
