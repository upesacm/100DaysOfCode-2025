#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight, value;
    double ratio;
} Item;

int cmp(const void *a, const void *b) {
    double r1 = ((Item*)a)->ratio, r2 = ((Item*)b)->ratio;
    return (r2 > r1) - (r2 < r1);
}

double fractionalKnapsack(int weights[], int values[], int n, int capacity) {
    Item arr[n];
    for (int i = 0; i < n; i++) {
        arr[i].weight = weights[i];
        arr[i].value = values[i];
        arr[i].ratio = (double)values[i] / weights[i];
    }
    qsort(arr, n, sizeof(Item), cmp);

    double totalValue = 0.0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (arr[i].weight <= capacity) {
            totalValue += arr[i].value;
            capacity -= arr[i].weight;
        } else {
            totalValue += arr[i].ratio * capacity;
            capacity = 0;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];
    printf("Enter weights:\n");
    for (int i = 0; i < n; i++) scanf("%d", &weights[i]);
    printf("Enter values:\n");
    for (int i = 0; i < n; i++) scanf("%d", &values[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    printf("Maximum value: %.2f\n", fractionalKnapsack(weights, values, n, capacity));
    return 0;
}
