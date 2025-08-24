#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int weight;
    int value;
    double ratio;
} Item;


int compare(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    if (itemB->ratio > itemA->ratio) return 1;
    else if (itemB->ratio < itemA->ratio) return -1;
    else return 0;
}


double fractionalKnapsack(int weights[], int values[], int n, int capacity) {
    Item items[n];
    for (int i = 0; i < n; i++) {
        items[i].weight = weights[i];
        items[i].value = values[i];
        items[i].ratio = (double)values[i] / weights[i];
    }

    
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (int i = 0; i < n && remainingCapacity > 0; i++) {
        if (items[i].weight <= remainingCapacity) {
        
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            
            totalValue += items[i].ratio * remainingCapacity;
            remainingCapacity = 0;
        }
    }

    return totalValue;
}

int main() {
    
    int weights1[] = {10, 20, 30};
    int values1[] =  {60, 100, 120};
    int capacity1 = 50;
    int n1 = sizeof(weights1) / sizeof(weights1[0]);
    printf("Max value (Example 1): %.1f\n", fractionalKnapsack(weights1, values1, n1, capacity1));  // ➜ 240.0

    
    int weights2[] = {5, 10};
    int values2[] =  {50, 60};
    int capacity2 = 10;
    int n2 = sizeof(weights2) / sizeof(weights2[0]);
    printf("Max value (Example 2): %.1f\n", fractionalKnapsack(weights2, values2, n2, capacity2));  // ➜ 80.0

    return 0;
}
