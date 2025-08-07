#include <stdio.h>

#define MAX 10000

void findPairsWithDiff(int arr[], int n, int k) {
    int hash[MAX] = {0};

    for (int i = 0; i < n; i++)
        hash[arr[i]] = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] + k < MAX && hash[arr[i] + k])
            printf("(%d, %d)\n", arr[i], arr[i] + k);
        if (arr[i] - k >= 0 && hash[arr[i] - k])
            printf("(%d, %d)\n", arr[i], arr[i] - k);
    }
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);

    findPairsWithDiff(arr, n, k);
    return 0;
}
