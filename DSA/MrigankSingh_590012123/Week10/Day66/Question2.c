#include <stdio.h>
#include <stdlib.h>

int maxProfit(int prices[], int n) {
    if (n <= 1) {
        return 0;
    }
    
    int minPrice = prices[0];
    int maxProfit = 0;
    
    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            int currentProfit = prices[i] - minPrice;
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
        }
    }
    
    return maxProfit;
}

int main() {
    int n;
    printf("Enter number of days: ");
    scanf("%d", &n);
    
    int* prices = (int*)malloc(n * sizeof(int));
    
    printf("Enter stock prices: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }
    
    int result = maxProfit(prices, n);
    
    if (result == 0) {
        printf("No profitable transaction possible\n");
    } else {
        printf("Maximum profit: %d\n", result);
    }
    
    free(prices);
    return 0;
}
