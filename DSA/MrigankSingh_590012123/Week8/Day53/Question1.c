#include <stdio.h>
#include <stdlib.h>

int consecutive_ones(int arr[], int n) {
    int maxCount = 0;
    int currentCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        } else {
            currentCount = 0;
        }
    }

    return maxCount;
}

int main() {
    int n;

    printf("Enter the number of elements in the binary array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Output: 0\n");
        return 0;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the binary elements (0 or 1):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] != 0 && arr[i] != 1) {
            printf("Error: Non-binary input detected. Using 0 instead.\n");
            arr[i] = 0;
        }
    }

    int result = consecutive_ones(arr, n);
    printf("Output: %d\n", result);

    free(arr);
    return 0;
}
