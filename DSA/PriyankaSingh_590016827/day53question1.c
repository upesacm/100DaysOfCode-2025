#include <stdio.h>

int findMaxConsecutiveOnes(int arr[], int n) {
    int max_count = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1)
            count++;
        else
            count = 0;
        if (count > max_count)
            max_count = count;
    }
    return max_count;
}

int main() {
    int n;
    printf("Enter number of elements in binary array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter binary elements (0 or 1):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = findMaxConsecutiveOnes(arr, n);
    printf("Maximum consecutive 1s: %d\n", result);

    return 0;
}
