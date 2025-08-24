#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first, second;
} Pair;

int compare(const void *a, const void *b) {
    return ((Pair *)a)->second - ((Pair *)b)->second;
}

int maxChain(Pair arr[], int n) {
    qsort(arr, n, sizeof(Pair), compare);

    int count = 1;
    int lastEnd = arr[0].second;
    for (int i = 1; i < n; i++) {
        if (arr[i].first > lastEnd) {
            count++;
            lastEnd = arr[i].second;
        }
    }
    return count;
}

int main() {
    int n;
    printf("Enter number of pairs: ");
    scanf("%d", &n);
    Pair arr[n];
    printf("Enter pairs (a b):\n");
    for (int i = 0; i < n; i++) scanf("%d %d", &arr[i].first, &arr[i].second);

    printf("Maximum chain length: %d\n", maxChain(arr, n));
    return 0;
}

