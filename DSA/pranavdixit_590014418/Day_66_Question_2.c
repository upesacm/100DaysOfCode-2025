#include <stdio.h>

int maxProfit(int prices[], int n) {
    int minPrice = prices[0], maxProfit = 0;
    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice) minPrice = prices[i];
        else if (prices[i] - minPrice > maxProfit)
            maxProfit = prices[i] - minPrice;
    }
    return maxProfit;
}

int main() {
    int arr1[] = {7, 1, 5, 3, 6, 4};
    printf("Max profit: %d\n", maxProfit(arr1, 6)); // 5

    int arr2[] = {7, 6, 4, 3, 1};
    printf("Max profit: %d\n", maxProfit(arr2, 5)); // 0
    return 0;
}
