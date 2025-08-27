#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first;
    int second;
} Pair;

int compare(const void* a, const void* b) {
    return ((Pair*)a)->second - ((Pair*)b)->second;
}

int maxChainLength(Pair pairs[], int n) {
    qsort(pairs, n, sizeof(Pair), compare);
    
    int count = 0;
    int lastEnd = -1;
    
    for (int i = 0; i < n; i++) {
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
    
    Pair* pairs = (Pair*)malloc(n * sizeof(Pair));
    
    printf("Enter pairs (first second): \n");
    for (int i = 0; i < n; i++) {
        printf("Pair %d: ", i + 1);
        scanf("%d %d", &pairs[i].first, &pairs[i].second);
    }
    
    int result = maxChainLength(pairs, n);
    printf("Maximum chain length: %d\n", result);
    
    free(pairs);
    return 0;
}
