#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int sum;
    int index;
    struct Node* next;
} Node;

#define SIZE 1000
Node* hashmap[SIZE];

int hash(int key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

void insert(int sum, int index) {
    int h = hash(sum);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = hashmap[h];
    hashmap[h] = newNode;
}

int search(int sum) {
    int h = hash(sum);
    Node* temp = hashmap[h];
    while (temp) {
        if (temp->sum == sum)
            return temp->index;
        temp = temp->next;
    }
    return -1;
}

int longestSubarrayWithSumK(int arr[], int n, int k) {
    for (int i = 0; i < SIZE; i++)
        hashmap[i] = NULL;
    int prefixSum = 0, maxLen = 0;
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        if (prefixSum == k)
            maxLen = i + 1;
        int prevIndex = search(prefixSum - k);
        if (prevIndex != -1 && i - prevIndex > maxLen)
            maxLen = i - prevIndex;
        if (search(prefixSum) == -1)
            insert(prefixSum, i);
    }
    return maxLen;
}

int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &k);
    printf("%d\n", longestSubarrayWithSumK(arr, n, k));
    return 0;
}
