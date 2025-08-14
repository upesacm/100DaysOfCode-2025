#include <stdio.h>

int isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2)/2; i++) {
        if (arr[i] < arr[2*i + 1])
            return 0;
        if (2*i + 2 < n && arr[i] < arr[2*i + 2])
            return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (isMaxHeap(arr, n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
