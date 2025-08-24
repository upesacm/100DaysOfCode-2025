
#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight, value;
    double ratio;
};

int compare(const void* a, const void* b) {
    double r1 = ((struct Item*)a)->ratio;
    double r2 = ((struct Item*)b)->ratio;
    return (r2 > r1) - (r2 < r1);
}

double fractionalKnapsack(int weights[], int values[], int n, int capacity) {
    struct Item items[n];
    for (int i = 0; i < n; i++) {
        items[i].weight = weights[i];
        items[i].value = values[i];
        items[i].ratio = (double)values[i] / weights[i];
    }
    qsort(items, n, sizeof(struct Item), compare);
    double totalValue = 0.0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].ratio * capacity;
            break;
        }
    }
    return totalValue;
}

int main() {
    int weights1[] = {10, 20, 30};
    int values1[] = {60, 100, 120};
    int n1 = sizeof(weights1) / sizeof(weights1[0]);
    printf("%.1f\n", fractionalKnapsack(weights1, values1, n1, 50));

    int weights2[] = {5, 10};
    int values2[] = {50, 60};
    int n2 = sizeof(weights2) / sizeof(weights2[0]);
    printf("%.1f\n", fractionalKnapsack(weights2, values2, n2, 10));
    return 0;
}
