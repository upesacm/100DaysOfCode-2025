#include <stdio.h>
#include <stdlib.h>

struct Item {
    double weight, value;
};

// Compare items by value/weight ratio (descending)
int cmp(const void *a, const void *b) {
    struct Item *x = (struct Item*)a;
    struct Item *y = (struct Item*)b;
    double r1 = x->value / x->weight;
    double r2 = y->value / y->weight;
    if (r1 < r2) return 1;
    else if (r1 > r2) return -1;
    else return 0;
}

double fractionalKnapsack(double weights[], double values[], int n, double capacity) {
    struct Item items[n];
    for (int i = 0; i < n; i++) {
        items[i].weight = weights[i];
        items[i].value = values[i];
    }

    // Sort by value/weight ratio
    qsort(items, n, sizeof(struct Item), cmp);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity <= 0) break;

        if (items[i].weight <= capacity) {
            // take full item
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // take fraction
            totalValue += (items[i].value / items[i].weight) * capacity;
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {
    double weights[] = {10, 20, 30};
    double values[]  = {60, 100, 120};
    int n = 3;
    double capacity = 50;

    double result = fractionalKnapsack(weights, values, n, capacity);
    printf("Maximum value = %.1f\n", result);  // formatted to 1 decimal

    return 0;
}

