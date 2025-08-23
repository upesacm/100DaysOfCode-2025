#include <stdio.h>

int candyDistribution(int ratings[], int n) {
    int candies[n];
    for (int i = 0; i < n; i++) candies[i] = 1;


    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    }

   
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
    int ratings[] = {1, 0, 2};
    int n = sizeof(ratings) / sizeof(ratings[0]);

    printf("Minimum Candies Required = %d\n", candyDistribution(ratings, n));
    return 0;
}

