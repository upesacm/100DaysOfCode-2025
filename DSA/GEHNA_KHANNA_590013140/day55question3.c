#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int sum;
    long long count;
    struct Node* next;
} Node;

#define SIZE 10007
Node* hashmap[SIZE];

int hash(int key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

void add(int sum) {
    int h = hash(sum);
    Node* temp = hashmap[h];
    while (temp) {
        if (temp->sum == sum) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->count = 1;
    newNode->next = hashmap[h];
    hashmap[h] = newNode;
}

long long getCount(int sum) {
    int h = hash(sum);
    Node* temp = hashmap[h];
    while (temp) {
        if (temp->sum == sum)
            return temp->count;
        temp = temp->next;
    }
    return 0;
}

long long numSubarraysWithSum(int arr[], int n, int goal) {
    for (int i = 0; i < SIZE; i++) hashmap[i] = NULL;
    long long total = 0;
    int prefix = 0;
    add(0);
    for (int i = 0; i < n; i++) {
        prefix += arr[i];
        total += getCount(prefix - goal);
        add(prefix);
    }
    return total;
}

int main() {
    int n, goal;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &goal);
    printf("%lld\n", numSubarraysWithSum(arr, n, goal));
    return 0;
}
