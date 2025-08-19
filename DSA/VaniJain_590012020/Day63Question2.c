#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int weight, value;
    double ratio;
} Item;
int compare(const void *a, const void *b) 
{
    Item *i1 = (Item *)a;
    Item *i2 = (Item *)b;
    if (i2->ratio > i1->ratio) return 1;
    else if (i2->ratio < i1->ratio) return -1;
    return 0;
}
double fractionalKnapsack(Item items[], int n, int capacity) 
{
    qsort(items, n, sizeof(Item), compare);
    double totalValue = 0.0;
    int currWeight = 0;
    for (int i = 0; i < n; i++) 
    {
        if (currWeight + items[i].weight <= capacity) 
        {
            currWeight += items[i].weight;
            totalValue += items[i].value;
        } else 
        {
            int remain = capacity - currWeight;
            totalValue += items[i].ratio * remain;
            break;
        }
    }
    return totalValue;
}
int main() 
{
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    Item items[n];
    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum total value in Knapsack = %.2f\n", maxValue);
    return 0;
}
