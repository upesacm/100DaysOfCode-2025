#include <stdio.h>


int maxProfit(int prices[], int n) {
    if (n == 0) return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++) {
        
        int profit = prices[i] - minPrice;
        if (profit > maxProfit)
            maxProfit = profit;

        
        if (prices[i] < minPrice)
            minPrice = prices[i];
    }

    return maxProfit;
}

int main() {
    
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int n1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("Max profit (Example 1): %d\n", maxProfit(prices1, n1));

    
    int prices2[] = {7, 6, 4, 3, 1};
    int n2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("Max profit (Example 2): %d\n", maxProfit(prices2, n2));  

    return 0;
}
