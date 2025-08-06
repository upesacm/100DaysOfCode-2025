
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000

bool hash[MAX] = {false};

void findPairsWithDiff(int arr[], int n, int k) {
    for (int i = 0; i < n; i++) {
        hash[arr[i]] = true;
    }

    for (int i = 0; i < n; i++) {
        if ((arr[i] + k) < MAX && hash[arr[i] + k])
            printf("(%d, %d)\n", arr[i], arr[i] + k);
    }
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);

    findPairsWithDiff(arr, n, k);

    return 0;
}
