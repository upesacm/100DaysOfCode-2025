#include <stdio.h>

int candy(int ratings[], int n) {
    int candies[n];
    for (int i = 0; i < n; i++) {
        candies[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = candies[i] > candies[i + 1] + 1 ? candies[i] : candies[i + 1] + 1;
        }
    }

    int total_candies = 0;
    for (int i = 0; i < n; i++) {
        total_candies += candies[i];
    }
    return total_candies;
}

int main() {
    int ratings1[] = {1, 0, 2};
    int n1 = sizeof(ratings1) / sizeof(ratings1[0]);
    printf("%d\n", candy(ratings1, n1));

    int ratings2[] = {1, 2, 2};
    int n2 = sizeof(ratings2) / sizeof(ratings2[0]);
    printf("%d\n", candy(ratings2, n2));

    return 0;
}
