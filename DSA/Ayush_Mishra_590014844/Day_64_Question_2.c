#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight, value;
    double ratio;
};

int compare(const void *a, const void *b) {
    double r1 = ((struct Item *)a)->ratio;
    double r2 = ((struct Item *)b)->ratio;
    return (r2 > r1) - (r2 < r1);
}

int main() {
    int n;
    double capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter weights and values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%lf", &capacity);

    qsort(items, n, sizeof(struct Item), compare);

    double total_value = 0.0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            total_value += items[i].value;
            capacity -= items[i].weight;
        } else {
            total_value += items[i].ratio * capacity;
            capacity = 0;
        }
    }

    printf("Maximum value in knapsack: %.2lf\n", total_value);
    return 0;
}
