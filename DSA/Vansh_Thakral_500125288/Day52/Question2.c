#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000

void findPairsWithDifference(int arr[], int n, int k) {
    bool hash[MAX] = {false};
    int i;


    for (i = 0; i < n; i++) {
        hash[arr[i]] = true;
    }


    for (i = 0; i < n; i++) {
        int val = arr[i];
        if (val + k < MAX && hash[val + k])
            printf("(%d, %d)\n", val, val + k);
        if (val - k >= 0 && hash[val - k])
            printf("(%d, %d)\n", val, val - k);
    }
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);

    findPairsWithDifference(arr, n, k);
    return 0;
}

