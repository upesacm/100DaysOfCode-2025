#include <stdio.h>

// 1️⃣ Minimum Platforms at Railway Station
int findMinimumPlatforms(int arr[], int dep[], int n) {
    int i = 0, j = 0;
    int platforms = 0, maxPlatforms = 0;

    // Sort arrival and departure arrays (simple bubble sort for clarity)
    for (int a = 0; a < n - 1; a++) {
        for (int b = a + 1; b < n; b++) {
            if (arr[a] > arr[b]) {
                int temp = arr[a]; arr[a] = arr[b]; arr[b] = temp;
            }
            if (dep[a] > dep[b]) {
                int temp = dep[a]; dep[a] = dep[b]; dep[b] = temp;
            }
        }
    }

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            if (platforms > maxPlatforms) maxPlatforms = platforms;
            i++;
        } else {
            platforms--;
            j++;
        }
    }
    return maxPlatforms;
}

// 2️⃣ Buy and Sell Stocks (Once)
int maxProfit(int prices[], int n) {
    int minPrice = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice)
            minPrice = prices[i];
        else if (prices[i] - minPrice > maxProfit)
            maxProfit = prices[i] - minPrice;
    }
    return maxProfit;
}

// 3️⃣ Distribute Candies Fairly
int minCandies(int ratings[], int n) {
    int candies[n];
    for (int i = 0; i < n; i++) candies[i] = 1;

    // Left-to-right pass
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    }

    // Right-to-left pass
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
            candies[i] = candies[i + 1] + 1;
    }

    int total = 0;
    for (int i = 0; i < n; i++) total += candies[i];
    return total;
}

// Main Driver
int main() {
    // Test 1: Minimum Platforms
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum Platforms Required = %d\n", findMinimumPlatforms(arr, dep, n1));

    // Test 2: Stock Buy-Sell
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n2 = sizeof(prices) / sizeof(prices[0]);
    printf("Maximum Profit = %d\n", maxProfit(prices, n2));

    // Test 3: Distribute Candies
    int ratings[] = {1, 0, 2};
    int n3 = sizeof(ratings) / sizeof(ratings[0]);
    printf("Minimum Candies Required = %d\n", minCandies(ratings, n3));

    return 0;
}
