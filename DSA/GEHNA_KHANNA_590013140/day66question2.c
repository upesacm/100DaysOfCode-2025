#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) { printf("0\n"); return 0; }

    int price, minPrice, maxProfit = 0;
    scanf("%d", &price);
    minPrice = price;

    for (int i = 1; i < n; i++) {
        scanf("%d", &price);
        if (price - minPrice > maxProfit) maxProfit = price - minPrice;
        if (price < minPrice) minPrice = price;
    }
    printf("%d\n", maxProfit);
    return 0;
}
