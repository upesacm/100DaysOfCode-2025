#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first, second;
} Pair;


int cmp(const void* a, const void* b) {
    Pair* x = (Pair*)a;
    Pair* y = (Pair*)b;
    return x->second - y->second;
}

int maxChainLength(Pair pairs[], int n) {
    qsort(pairs, n, sizeof(Pair), cmp);

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
    Pair pairs[] = {{5, 24}, {15, 25}, {27, 40}, {50, 60}};
    int n = sizeof(pairs) / sizeof(pairs[0]);

    printf("Maximum Chain Length: %d\n", maxChainLength(pairs, n));
    return 0;
}

