#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Pair;

int compare(const void *a, const void *b) {
    return ((Pair *)a)->end - ((Pair *)b)->end;
}

int main() {
    int n;
    printf("Enter number of pairs: ");
    scanf("%d", &n);

    Pair pairs[n];
    printf("Enter pairs (start end):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pairs[i].start, &pairs[i].end);
    }

    qsort(pairs, n, sizeof(Pair), compare);

    int count = 1;
    int last_end = pairs[0].end;

    for (int i = 1; i < n; i++) {
        if (pairs[i].start > last_end) {
            count++;
            last_end = pairs[i].end;
        }
    }

    printf("Maximum length of chain: %d\n", count);
    return 0;
}
