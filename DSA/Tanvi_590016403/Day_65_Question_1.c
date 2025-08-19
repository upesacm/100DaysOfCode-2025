#include <stdio.h>
#include <stdlib.h>

// ----------- 1. Minimum Coins ------------
void minCoins(int coins[], int n, int amount) {
    int count = 0, i;
    printf("Minimum Coins for amount %d: ", amount);
    for (i = n - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            printf("%d ", coins[i]);
            count++;
        }
    }
    printf("\nTotal Coins = %d\n", count);
}

// ----------- 2. Maximum Chain of Pairs ------------
struct Pair {
    int first, second;
};

int comparePairs(const void* a, const void* b) {
    return ((struct Pair*)a)->second - ((struct Pair*)b)->second;
}

void maxChainPairs(struct Pair arr[], int n) {
    qsort(arr, n, sizeof(struct Pair), comparePairs);

    int count = 1;
    int end = arr[0].second;

    for (int i = 1; i < n; i++) {
        if (arr[i].first > end) {
            count++;
            end = arr[i].second;
        }
    }

    printf("Maximum Chain Length = %d\n", count);
}

// ----------- 3. Schedule Tasks Without Overlap ------------
struct Interval {
    int start, end;
};

int compareIntervals(const void* a, const void* b) {
    return ((struct Interval*)a)->end - ((struct Interval*)b)->end;
}

void minRemovalsForNonOverlap(struct Interval arr[], int n) {
    qsort(arr, n, sizeof(struct Interval), compareIntervals);

    int count = 1;
    int end = arr[0].end;

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= end) {
            count++;
            end = arr[i].end;
        }
    }

    printf("Remove %d -> Remaining %d\n", n - count, count);
}

// ----------- MAIN FUNCTION ------------
int main() {
    // 1. Minimum Coins Example
    int coins1[] = {1, 2, 5, 10};
    int n1 = sizeof(coins1) / sizeof(coins1[0]);
    minCoins(coins1, n1, 23);

    int coins2[] = {1, 5, 6, 9};
    int n2 = sizeof(coins2) / sizeof(coins2[0]);
    minCoins(coins2, n2, 11);

    printf("\n");

    // 2. Maximum Chain of Pairs Example
    struct Pair pairs1[] = {{5, 24}, {15, 25}, {27, 40}, {50, 60}};
    int n3 = sizeof(pairs1) / sizeof(pairs1[0]);
    maxChainPairs(pairs1, n3);

    struct Pair pairs2[] = {{1, 2}, {2, 3}, {3, 4}};
    int n4 = sizeof(pairs2) / sizeof(pairs2[0]);
    maxChainPairs(pairs2, n4);

    printf("\n");

    // 3. Schedule Tasks Without Overlap Example
    struct Interval intervals1[] = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int n5 = sizeof(intervals1) / sizeof(intervals1[0]);
    minRemovalsForNonOverlap(intervals1, n5);

    struct Interval intervals2[] = {{1, 2}, {1, 2}, {1, 2}};
    int n6 = sizeof(intervals2) / sizeof(intervals2[0]);
    minRemovalsForNonOverlap(intervals2, n6);

    return 0;
}
