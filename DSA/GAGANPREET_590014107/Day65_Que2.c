#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first;
    int second;
} Pair;

int compare(const void *a, const void *b) {
    Pair *pair1 = (Pair *)a;
    Pair *pair2 = (Pair *)b;
    return pair1->second - pair2->second;
}

int maxChainLength(Pair pairs[], int n) {
    qsort(pairs, n, sizeof(Pair), compare);
    int count = 1;
    int lastEnd = pairs[0].second;

    for (int i = 1; i < n; i++) {
        if (pairs[i].first > lastEnd) {
            count++;
            lastEnd = pairs[i].second;
        }
    }
    return count;
}

int main() {
    Pair pairs1[] = {{5, 24}, {15, 25}, {27, 40}, {50, 60}};
    int result1 = maxChainLength(pairs1, 4);
    printf("%d\n", result1);

    Pair pairs2[] = {{1, 2}, {2, 3}, {3, 4}};
    int result2 = maxChainLength(pairs2, 3);
    printf("%d\n", result2);

    return 0;
}
