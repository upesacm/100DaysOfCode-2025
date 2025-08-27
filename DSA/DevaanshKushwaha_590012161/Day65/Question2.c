#include <stdio.h>
#include <stdlib.h>

// Pair structure
typedef struct {
    int first, second;
} Pair;

// Sort pairs by second value
int compare(const void *a, const void *b) {
    return ((Pair*)a)->second - ((Pair*)b)->second;
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
    int n;
    printf("Enter number of pairs: ");
    scanf("%d", &n);

    Pair pairs[n];
    printf("Enter pairs (a b):\n");
    for (int i = 0; i < n; i++) scanf("%d %d", &pairs[i].first, &pairs[i].second);

    printf("Maximum length of chain: %d\n", maxChainLength(pairs, n));
    return 0;
}
