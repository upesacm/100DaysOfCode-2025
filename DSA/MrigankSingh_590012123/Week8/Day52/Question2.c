#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Pair {
    int first;
    int second;
} Pair;

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

Pair* difference_pair(int arr[], int n, int k, int* pairCount) {
    if (k < 0 || n < 2) {
        *pairCount = 0;
        return NULL;
    }

    qsort(arr, n, sizeof(int), compare);

    Pair* pairs = (Pair*)malloc(n * n * sizeof(Pair));
    *pairCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i] - arr[j]) == k) {
                pairs[*pairCount].first = arr[i];
                pairs[*pairCount].second = arr[j];
                (*pairCount)++;
            }
        }
    }

    return pairs;
}

void print_Pairs(Pair* pairs, int pairCount) {
    printf("[");
    for (int i = 0; i < pairCount; i++) {
        printf("(%d, %d)", pairs[i].first, pairs[i].second);
        if (i < pairCount - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("[]\n");
        return 0;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter the difference (k): ");
    scanf("%d", &k);

    int pairCount;
    Pair* pairs = difference_pair(arr, n, k, &pairCount);

    print_Pairs(pairs, pairCount);

    free(arr);
    free(pairs);
    return 0;
}
