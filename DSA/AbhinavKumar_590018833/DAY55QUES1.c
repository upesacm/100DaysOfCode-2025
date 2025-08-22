// 1. Longest Subarray with Sum K
// A problem that demonstrates prefix sum optimization and teaches hash-based subarray finding algorithms using cumulative sum techniques for efficient target sum detection and length maximization operations.

// Given an array and integer k, find the length of the longest subarray with sum equal to k using prefix sum and hash map approach. This operation is fundamental in subarray optimization and target sum analysis where you need to find maximum length segments meeting specific sum criteria efficiently. The technique uses prefix sum tracking with hash-based storage to detect when cumulative sums differ by exactly k, enabling O(n) time complexity. This concept is essential in financial analysis, performance tracking, and data segmentation where finding longest periods meeting target metrics enables trend analysis and performance optimization.

// This teaches prefix sum algorithms and hash-based subarray optimization techniques that are essential for target sum analysis and efficient length maximization operations.

// Your task: Implement prefix sum tracking with hash map storage to efficiently find longest subarrays meeting exact sum requirements.

// Examples
// Input:

// arr = [10, 5, 2, 7, 1, 9], k = 15
// Output:

// 4
// Input:

// arr = [1, 2, 3], k = 3
// Output:

// 2





#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1000

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node** table;
    int size;
} HashTable;

HashTable* createHashTable(int size) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = size;
    ht->table = (Node**)calloc(size, sizeof(Node*));
    return ht;
}

int hashFunction(int key, int size) {
    return abs(key) % size;
}

void hash_insert(HashTable* ht, int key, int value) {
    int index = hashFunction(key, ht->size);
    Node* current = ht->table[index];

    while (current != NULL) {
        if (current->key == key) {
            return;
        }
        current = current->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

Node* hash_search(HashTable* ht, int key) {
    int index = hashFunction(key, ht->size);
    Node* current = ht->table[index];
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void freeHashTable(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        Node* current = ht->table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

int longestSubarrayWithSum(int arr[], int n, int k) {
    HashTable* prefix_map = createHashTable(TABLE_SIZE);
    
    hash_insert(prefix_map, 0, -1);
    
    int current_sum = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        current_sum += arr[i];

        int remainder = current_sum - k;
        Node* found = hash_search(prefix_map, remainder);

        if (found != NULL) {
            int length = i - found->value;
            if (length > max_len) {
                max_len = length;
            }
        }
        
        hash_insert(prefix_map, current_sum, i);
    }
    
    freeHashTable(prefix_map);
    return max_len;
}

int main() {
    int arr1[] = {10, 5, 2, 7, 1, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 15;
    printf("Input: arr = {10, 5, 2, 7, 1, 9}, k = %d\n", k1);
    printf("Output: %d\n\n", longestSubarrayWithSum(arr1, n1, k1));

    int arr2[] = {1, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 3;
    printf("Input: arr = {1, 2, 3}, k = %d\n", k2);
    printf("Output: %d\n", longestSubarrayWithSum(arr2, n2, k2));

    return 0;
}