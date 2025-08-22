#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode** buckets;
    int size;
} HashMap;

HashMap* createHashMap(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->size = size;
    map->buckets = (HashNode**)calloc(size, sizeof(HashNode*));
    return map;
}

int hash(int key, int size) {
    return abs(key) % size;
}

void put(HashMap* map, int key, int value) {
    int index = hash(key, map->size);
    HashNode* node = map->buckets[index];
    
    while (node) {
        if (node->key == key) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}

int get(HashMap* map, int key, int* found) {
    int index = hash(key, map->size);
    HashNode* node = map->buckets[index];
    
    while (node) {
        if (node->key == key) {
            *found = 1;
            return node->value;
        }
        node = node->next;
    }
    
    *found = 0;
    return -1;
}

void freeHashMap(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        HashNode* node = map->buckets[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

int longestSubarraySum(int* arr, int n, int k) {
    HashMap* map = createHashMap(n * 2);
    int prefixSum = 0;
    int maxLen = 0;
    
    put(map, 0, -1);
    
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        
        int found;
        int prevIndex = get(map, prefixSum - k, &found);
        if (found) {
            int len = i - prevIndex;
            if (len > maxLen) {
                maxLen = len;
            }
        }
        
        int currentFound;
        get(map, prefixSum, &currentFound);
        if (!currentFound) {
            put(map, prefixSum, i);
        }
    }
    
    freeHashMap(map);
    return maxLen;
}

int main() {
    int n, k;
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &k);
    
    int result = longestSubarraySum(arr, n, k);
    printf("%d\n", result);
    
    free(arr);
    return 0;
}
