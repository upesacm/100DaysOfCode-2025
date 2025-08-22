#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first, second;
} Pair;

int comparePairs(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    return p1->second - p2->second;
}

int maxChainLength(Pair pairs[], int n) {
    qsort(pairs, n, sizeof(Pair), comparePairs);
    int count = 1, last = pairs[0].second;
    for (int i = 1; i < n; i++) {
        if (pairs[i].first > last) {
            count++;
            last = pairs[i].second;
        }
    }
    return count;
}

int main() {
    int n;
    printf("Enter number of pairs: ");
    scanf("%d", &n);
    Pair pairs[n];
    printf("Enter pairs (a b):\n");
    for (int i = 0; i < n; i++) scanf("%d %d", &pairs[i].first, &pairs[i].second);
    printf("Maximum chain length: %d\n", maxChainLength(pairs, n));
    return 0;
}
