#include <stdio.h>

int main() {
    int n;
    printf("Enter number of days: ");
    scanf("%d", &n);

    int prices[n];
    printf("Enter stock prices:\n");
    for(int i=0;i<n;i++) scanf("%d",&prices[i]);

    int min_price = prices[0], max_profit = 0;
    for(int i=1;i<n;i++) {
        if(prices[i] - min_price > max_profit)
            max_profit = prices[i] - min_price;
        if(prices[i] < min_price)
            min_price = prices[i];
    }

    printf("Maximum profit with one transaction: %d\n", max_profit);
    return 0;
}
