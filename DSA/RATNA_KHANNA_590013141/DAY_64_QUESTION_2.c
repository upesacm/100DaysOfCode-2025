#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight, value;
    double ratio;
};

int cmp(const void *a,const void *b){
    double r1=((struct Item*)a)->ratio;
    double r2=((struct Item*)b)->ratio;
    return r2>r1?1:-1;
}

double fractionalKnapsack(int weights[],int values[],int n,int capacity){
    struct Item items[n];
    for(int i=0;i<n;i++){
        items[i].weight=weights[i];
        items[i].value=values[i];
        items[i].ratio=(double)values[i]/weights[i];
    }
    qsort(items,n,sizeof(struct Item),cmp);
    double total=0.0;
    for(int i=0;i<n;i++){
        if(capacity>=items[i].weight){
            printf("Taking full item with weight %d and value %d\n",items[i].weight,items[i].value);
            total+=items[i].value;
            capacity-=items[i].weight;
        } else {
            printf("Taking %.2f fraction of item with weight %d and value %d\n",(double)capacity/items[i].weight,items[i].weight,items[i].value);
            total+=items[i].ratio*capacity;
            break;
        }
    }
    return total;
}

int main(){
    int n,capacity;
    printf("Enter number of items: ");
    scanf("%d",&n);
    int weights[n],values[n];
    printf("Enter weights: ");
    for(int i=0;i<n;i++) scanf("%d",&weights[i]);
    printf("Enter values: ");
    for(int i=0;i<n;i++) scanf("%d",&values[i]);
    printf("Enter knapsack capacity: ");
    scanf("%d",&capacity);
    double result=fractionalKnapsack(weights,values,n,capacity);
    printf("Maximum value in knapsack = %.1f\n",result);
    return 0;
}
