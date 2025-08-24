#include <stdio.h>
#include <stdlib.h>

struct Pair {
    int first, second;
};

// Comparison function to sort by second element
int comparePairs(const void *a, const void *b) {
    struct Pair *p1 = (struct Pair *)a;
    struct Pair *p2 = (struct Pair *)b;
    return p1->second - p2->second;
}

int maxChain(struct Pair pairs[], int n) {
    qsort(pairs, n, sizeof(struct Pair), comparePairs);

    int count = 1;  // At least one pair
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
    struct Pair pairs1[] = {{5, 24}, {15, 25}, {27, 40}, {50, 60}};
    int n1 = sizeof(pairs1) / sizeof(pairs1[0]);
    printf("Maximum Chain Length: %d\n", maxChain(pairs1, n1));

    struct Pair pairs2[] = {{1, 2}, {2, 3}, {3, 4}};
    int n2 = sizeof(pairs2) / sizeof(pairs2[0]);
    printf("Maximum Chain Length: %d\n", maxChain(pairs2, n2));

    return 0;
}

