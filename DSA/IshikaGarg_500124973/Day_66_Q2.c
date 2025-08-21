#include <stdio.h>

int maxProfit(int prices[], int n) {
    int min_price = prices[0];
    int max_profit = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] < min_price)
            min_price = prices[i];  // update min price
        else if (prices[i] - min_price > max_profit)
            max_profit = prices[i] - min_price;  // check profit
    }
    return max_profit;
}

int main() {
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int n1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("%d\n", maxProfit(prices1, n1)); // Output: 5

    int prices2[] = {7, 6, 4, 3, 1};
    int n2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("%d\n", maxProfit(prices2, n2)); // Output: 0

    return 0;
}

