#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int sum;
    int index;
    struct Node* next;
} Node;


#define HASH_SIZE 1000

Node* hashTable[HASH_SIZE];


int hash(int key) {
    return abs(key) % HASH_SIZE;
}


void insert(int sum, int index) {
    int h = hash(sum);
    Node* curr = hashTable[h];
    while (curr) {
        if (curr->sum == sum) return; 
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}


int search(int sum) {
    int h = hash(sum);
    Node* curr = hashTable[h];
    while (curr) {
        if (curr->sum == sum) return curr->index;
        curr = curr->next;
    }
    return -1;
}


void clearHash() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = hashTable[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}


int longestSubarrayWithSumK(int arr[], int n, int k) {
    clearHash();
    int maxLen = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == k) {
            maxLen = i + 1;
        }

        int prevIndex = search(sum - k);
        if (prevIndex != -1) {
            int len = i - prevIndex;
            if (len > maxLen) {
                maxLen = len;
            }
        }

        insert(sum, i);
    }

    return maxLen;
}

int main() {
    
    int arr1[] = {10, 5, 2, 7, 1, 9};
    int k1 = 15;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Longest subarray with sum %d: %d\n", k1, longestSubarrayWithSumK(arr1, n1, k1));  // ➜ 4

    
    int arr2[] = {1, 2, 3};
    int k2 = 3;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Longest subarray with sum %d: %d\n", k2, longestSubarrayWithSumK(arr2, n2, k2));  // ➜ 2

    return 0;
}
