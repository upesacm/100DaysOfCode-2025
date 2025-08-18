#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int weight, value;
    double ratio;
} Item;


int cmp(const void* a, const void* b) {
    Item* x = (Item*)a;
    Item* y = (Item*)b;
    if (y->ratio > x->ratio) return 1;
    else if (y->ratio < x->ratio) return -1;
    return 0;
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
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int weights[] = {10, 20, 30};
    int values[] = {60, 100, 120};
    int capacity = 50;
    int n = sizeof(weights) / sizeof(weights[0]);

    printf("%.2f\n", fractionalKnapsack(weights, values, n, capacity));
    return 0;
}

