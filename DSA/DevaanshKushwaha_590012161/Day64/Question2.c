#include <stdio.h>
#include <stdlib.h>

// Structure for an item
typedef struct {
    int weight, value;
    double ratio;
} Item;

// Comparator for sorting items by ratio in descending order
int compare(const void *a, const void *b) {
    Item *i1 = (Item *)a;
    Item *i2 = (Item *)b;
    if (i1->ratio < i2->ratio) return 1;
    else if (i1->ratio > i2->ratio) return -1;
    return 0;
}

// Function to solve fractional knapsack
double fractionalKnapsack(int weights[], int values[], int n, int capacity) {
    Item items[n];
    for (int i = 0; i < n; i++) {
        items[i].weight = weights[i];
        items[i].value = values[i];
        items[i].ratio = (double)values[i] / weights[i];
    }

    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;
    int remaining = capacity;

    for (int i = 0; i < n && remaining > 0; i++) {
        if (items[i].weight <= remaining) {
            totalValue += items[i].value;
            remaining -= items[i].weight;
        } else {
            totalValue += items[i].ratio * remaining;
            remaining = 0;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];
    printf("Enter weights: ");
    for (int i = 0; i < n; i++) scanf("%d", &weights[i]);

    printf("Enter values: ");
    for (int i = 0; i < n; i++) scanf("%d", &values[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    double result = fractionalKnapsack(weights, values, n, capacity);
    printf("Maximum value = %.2f\n", result);

    return 0;
}
