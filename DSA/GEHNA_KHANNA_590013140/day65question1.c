#include <stdio.h>

int main() {
    int n, amount;
    scanf("%d", &n);
    int coins[n];
    for (int i = 0; i < n; i++) scanf("%d", &coins[i]);
    scanf("%d", &amount);

    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
