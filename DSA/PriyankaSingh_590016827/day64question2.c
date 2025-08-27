#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight, value;
    double ratio;
} Item;

int compare(const void *a, const void *b) {
    double r1 = ((Item *)a)->ratio;
    double r2 = ((Item *)b)->ratio;
    if (r1 < r2) return 1;
    if (r1 > r2) return -1;
    return 0;
}

double fractionalKnapsack(Item arr[], int n, int capacity) {
    qsort(arr, n, sizeof(Item), compare);
    double totalValue = 0.0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (arr[i].weight <= capacity) {
            totalValue += arr[i].value;
            capacity -= arr[i].weight;
        } else {
            totalValue += arr[i].value * ((double)capacity / arr[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    Item arr[n];
    printf("Enter weights:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i].weight);
    printf("Enter values:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i].value);
    printf("Enter capacity: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n; i++)
        arr[i].ratio = (double)arr[i].value / arr[i].weight;

    printf("Maximum value: %.2f\n", fractionalKnapsack(arr, n, capacity));
    return 0;
}
