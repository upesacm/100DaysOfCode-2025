#include <stdio.h>

int distributeCandies(int ratings[], int n) {
    int candies[n];
    for (int i = 0; i < n; i++) candies[i] = 1;
    for (int i = 1; i < n; i++)
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    for (int i = n - 2; i >= 0; i--)
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
            candies[i] = candies[i + 1] + 1;
    int total = 0;
    for (int i = 0; i < n; i++) total += candies[i];
    return total;
}

int main() {
    int n;
    printf("Enter number of children: ");
    scanf("%d", &n);
    int ratings[n];
    printf("Enter ratings: ");
    for (int i = 0; i < n; i++) scanf("%d", &ratings[i]);
    printf("Minimum candies needed: %d\n", distributeCandies(ratings, n));
    return 0;
}
