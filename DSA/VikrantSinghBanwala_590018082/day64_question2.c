#include <stdio.h>

struct Item {
    int value;
    int weight;
    float ratio;
};

int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    return (item2->ratio > item1->ratio) - (item2->ratio < item1->ratio);
}

float fractionalKnapsack(int weights[], int values[], int n, int capacity) {
    struct Item items[n];
    for (int i = 0; i < n; i++) {
        items[i].value = values[i];
        items[i].weight = weights[i];
        items[i].ratio = (float)values[i] / weights[i];
    }

    qsort(items, n, sizeof(items[0]), compare);

    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity <= 0) break;

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
    int weights1[] = {10, 20, 30};
    int values1[] = {60, 100, 120};
    int capacity1 = 50;
    
    int weights2[] = {5, 10};
    int values2[] = {50, 60};
    int capacity2 = 10;

    printf("%.1f\n", fractionalKnapsack(weights1, values1, 3, capacity1));
    printf("%.1f\n", fractionalKnapsack(weights2, values2, 2, capacity2));

    return 0;
}
