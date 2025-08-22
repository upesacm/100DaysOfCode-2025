#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight, value;
    double ratio;
} Item;

int cmp(const void *a, const void *b) {
    double r1 = ((Item *)a)->ratio, r2 = ((Item *)b)->ratio;
    return (r2 > r1) - (r2 < r1);
}

double fractionalKnapsack(int weights[], int values[], int n, int capacity) {
    Item items[n];
    for (int i = 0; i < n; i++) {
        items[i].weight = weights[i];
        items[i].value = values[i];
        items[i].ratio = (double)values[i] / weights[i];
    }
    qsort(items, n, sizeof(Item), cmp);

    double totalValue = 0.0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].ratio * capacity;
            capacity = 0;
        }
    }
    return totalValue;
}

int main() {
    int w1[] = {10, 20, 30}, v1[] = {60, 100, 120};
    printf("Max value: %.1f\n", fractionalKnapsack(w1, v1, 3, 50)); // 240.0

    int w2[] = {5, 10}, v2[] = {50, 60};
    printf("Max value: %.1f\n", fractionalKnapsack(w2, v2, 2, 10)); // 80.0
    return 0;
}
