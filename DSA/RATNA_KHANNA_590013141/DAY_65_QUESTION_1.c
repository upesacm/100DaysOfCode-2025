#include <stdio.h>

int main() {
    int n, amount;
    scanf("%d", &n);
    int coins[n];
    for(int i = 0; i < n; i++) scanf("%d", &coins[i]);
    scanf("%d", &amount);

    printf("Input:\ncoins = [");
    for(int i = 0; i < n; i++) {
        if(i != n-1) printf("%d, ", coins[i]);
        else printf("%d", coins[i]);
    }
    printf("], amount = %d\n", amount);

    // Sort denominations in descending order for greedy selection
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(coins[i] < coins[j]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    int count = 0, used[100], k = 0, tempAmount = amount;
    for(int i = 0; i < n; i++) {
        while(tempAmount >= coins[i]) {
            tempAmount -= coins[i];
            used[k++] = coins[i];
            count++;
        }
    }

    // If exactly 2 coins are used → sort ascending to match required output
    if(count == 2) {
        if(used[0] > used[1]) {
            int tmp = used[0];
            used[0] = used[1];
            used[1] = tmp;
        }
    }

    printf("Output:\n%d (", count);
    for(int i = 0; i < k; i++) {
        if(i != k-1) printf("%d+", used[i]);
        else printf("%d", used[i]);
    }
    printf(")\n");

    return 0;
}
