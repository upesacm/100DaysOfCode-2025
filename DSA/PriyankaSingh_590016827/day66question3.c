#include <stdio.h>
#include <stdlib.h>

// Distribute Candies Fairly
int distributeCandies(int ratings[], int n) {
    if (n == 0) return 0;
    int *candies = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        candies[i] = 1;
    }

    // Left to right pass
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right to left pass
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
            candies[i] = candies[i + 1] + 1;
        }
    }

    int total_candies = 0;
    for (int i = 0; i < n; i++) {
        total_candies += candies[i];
    }

    free(candies);
    return total_candies;
}

int main() {
    // Example 1
    int ratings1[] = {1, 0, 2};
    int n1 = sizeof(ratings1) / sizeof(ratings1[0]);
    printf("Minimum candies needed: %d\n", distributeCandies(ratings1, n1));

    // Example 2
    int ratings2[] = {1, 2, 2};
    int n2 = sizeof(ratings2) / sizeof(ratings2[0]);
    printf("Minimum candies needed: %d\n", distributeCandies(ratings2, n2));

    return 0;
}
