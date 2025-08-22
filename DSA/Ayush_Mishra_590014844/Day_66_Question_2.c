#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int prices[n];
    for (int i = 0; i < n; i++) scanf("%d", &prices[i]);

    int min_price = prices[0], max_profit = 0;
    for (int i = 1; i < n; i++) {
        if (prices[i] < min_price) min_price = prices[i];
        int profit = prices[i] - min_price;
        if (profit > max_profit) max_profit = profit;
    }

    printf("%d\n", max_profit);
    return 0;
}
