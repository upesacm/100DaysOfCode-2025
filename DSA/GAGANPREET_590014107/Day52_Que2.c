
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
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
    ht->table = (Node**)malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}
void insert(HashTable* ht, int value) {
    int index = abs(value) % ht->size;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}
int exists(HashTable* ht, int value) {
    int index = abs(value) % ht->size;
    Node* current = ht->table[index];
    while (current) {
        if (current->value == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
void freeHashTable(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        Node* current = ht->table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}
void findPairsWithDifference(int arr[], int n, int k) {
    HashTable* ht = createHashTable(n);
    for (int i = 0; i < n; i++) {
        insert(ht, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (exists(ht, arr[i] + k)) {
            printf("(%d, %d)\n", arr[i], arr[i] + k);
        }
        if (exists(ht, arr[i] - k)) {
            printf("(%d, %d)\n", arr[i], arr[i] - k);
        }
    }
    freeHashTable(ht);
}
int main() {
    int arr1[] = {1, 5, 3, 4, 2};
    int k1 = 2;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    findPairsWithDifference(arr1, n1, k1);
    int arr2[] = {8, 12, 16, 4, 0, 20};
    int k2 = 4;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    findPairsWithDifference(arr2, n2, k2);
    return 0;
}
