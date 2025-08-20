#include <stdio.h>

int candy(int ratings[], int n) {
    int candies[n];
    for (int i = 0; i < n; i++)
        candies[i] = 1; // at least 1 candy each

    // Left to right
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    }

    // Right to left
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
            candies[i] = candies[i + 1] + 1;
    }

    int total = 0;
    for (int i = 0; i < n; i++)
        total += candies[i];

    return total;
}

int main() {
    int ratings1[] = {1, 0, 2};
    int n1 = sizeof(ratings1) / sizeof(ratings1[0]);
    printf("%d\n", candy(ratings1, n1)); // Output: 5

    int ratings2[] = {1, 2, 2};
    int n2 = sizeof(ratings2) / sizeof(ratings2[0]);
    printf("%d\n", candy(ratings2, n2)); // Output: 4

    return 0;
}

