#include <stdio.h>

int totalFruit(int fruits[], int n) {
    int maxLen = 0;
    int lastFruit = -1, secondLastFruit = -1;
    int lastCount = 0, currLen = 0;

    for (int i = 0; i < n; i++) {
        if (fruits[i] == lastFruit || fruits[i] == secondLastFruit)
            currLen++;
        else
            currLen = lastCount + 1;

        if (fruits[i] == lastFruit)
            lastCount++;
        else {
            lastCount = 1;
            secondLastFruit = lastFruit;
            lastFruit = fruits[i];
        }

        if (currLen > maxLen)
            maxLen = currLen;
    }

    return maxLen;
}

int main() {
    int fruits[] = {0, 1, 2, 2};
    int n = sizeof(fruits) / sizeof(fruits[0]);

    printf("Max fruits in two baskets: %d\n", totalFruit(fruits, n)); // Output: 3
    return 0;
}
