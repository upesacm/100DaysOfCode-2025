#include <stdio.h>
#include <stdlib.h>

int distributeCandies(int ratings[], int n) {
    if (n <= 0) {
        return 0;
    }
    
    int* candies = (int*)malloc(n * sizeof(int));
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
    
    int totalCandies = 0;
    for (int i = 0; i < n; i++) {
        totalCandies += candies[i];
    }
    
    free(candies);
    return totalCandies;
}

int main() {
    int n;
    printf("Enter number of children: ");
    scanf("%d", &n);
    
    int* ratings = (int*)malloc(n * sizeof(int));
    
    printf("Enter ratings for each child: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &ratings[i]);
    }
    
    int result = distributeCandies(ratings, n);
    printf("Minimum candies required: %d\n", result);
    
    free(ratings);
    return 0;
}
