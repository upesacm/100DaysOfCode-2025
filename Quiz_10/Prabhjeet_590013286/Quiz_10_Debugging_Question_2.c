#include <stdio.h>
#include <stdlib.h>

// Each item has value, weight, and value-per-weight ratio
struct Item {
    int value;
    int weight;
    double valuePerKg;
};

// Sort items by value-per-kg (best deal first)
int sortByValuePerKg(const void* a, const void* b) {
    double r1 = ((struct Item*)a)->valuePerKg;
    double r2 = ((struct Item*)b)->valuePerKg;
    return (r2 > r1) - (r2 < r1);  // Descending order
}

// Function to fill the bag with best value
double fillBagSmartly(int weights[], int values[], int n, int capacity) {
    struct Item items[n];

    // Fill item list and calculate value per kg
    for (int i = 0; i < n; i++) {
        items[i].value = values[i];
        items[i].weight = weights[i];
        items[i].valuePerKg = (double)values[i] / weights[i];
    }

    // Sort items by best value per kg
    qsort(items, n, sizeof(struct Item), sortByValuePerKg);

    double totalValue = 0.0;
    int currentWeight = 0;

    // Pick items until the bag is full
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Take full item
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take part of item
            int spaceLeft = capacity - currentWeight;
            totalValue += items[i].valuePerKg * spaceLeft;
            break;  
        }
    }

    return totalValue;
}

int main() {
    int weights[] = {10, 20, 30};
    int values[]  = {60, 100, 120};
    int n = sizeof(weights) / sizeof(weights[0]);
    int capacity = 50;

    double result = fillBagSmartly(weights, values, n, capacity);
    printf("Best value you can carry: %.2f\n", result);  // Output: 240.00

    return 0;
}
