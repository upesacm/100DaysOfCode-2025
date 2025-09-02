#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    double ratio;
} Item;

int compare(const void* a, const void* b) {
    double ratio1 = ((Item*)a)->ratio;
    double ratio2 = ((Item*)b)->ratio;
    return (ratio2 > ratio1) - (ratio2 < ratio1);
}

double fractionalKnapsack(int weights[], int values[], int n, int capacity) {
    Item* items = (Item*)malloc(n * sizeof(Item));
    for (int i = 0; i < n; i++) {
        items[i].weight = weights[i];
        items[i].value = values[i];
        items[i].ratio = (double)values[i] / weights[i];
    }
    
    qsort(items, n, sizeof(Item), compare);
    
    double totalValue = 0.0;
    int remainingCapacity = capacity;
    
    for (int i = 0; i < n; i++) {
        if (remainingCapacity >= items[i].weight) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            double fraction = (double)remainingCapacity / items[i].weight;
            totalValue += fraction * items[i].value;
            break;
        }
    }
    
    free(items);
    return totalValue;
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    int* weights = (int*)malloc(n * sizeof(int));
    int* values = (int*)malloc(n * sizeof(int));
    
    printf("Enter weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    
    printf("Enter values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    
    printf("Maximum value: %.1f\n", fractionalKnapsack(weights, values, n, capacity));
    
    free(weights);
    free(values);
    return 0;
}
