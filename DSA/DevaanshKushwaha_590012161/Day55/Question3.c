#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int count;
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

void increment(HashMap* map, int key) {
    int index = hash(key, map->size);
    HashNode* node = map->buckets[index];
    
    while (node) {
        if (node->key == key) {
            node->count++;
            return;
        }
        node = node->next;
    }
    
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}

int getCount(HashMap* map, int key) {
    int index = hash(key, map->size);
    HashNode* node = map->buckets[index];
    
    while (node) {
        if (node->key == key) {
            return node->count;
        }
        node = node->next;
    }
    
    return 0;
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

int numSubarraysWithSum(int* nums, int n, int goal) {
    HashMap* map = createHashMap(n + 1);
    int prefixSum = 0;
    int result = 0;
    
    increment(map, 0);
    
    for (int i = 0; i < n; i++) {
        prefixSum += nums[i];
        
        int target = prefixSum - goal;
        result += getCount(map, target);
        
        increment(map, prefixSum);
    }
    
    freeHashMap(map);
    return result;
}

int main() {
    int n, goal;
    scanf("%d", &n);
    
    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    scanf("%d", &goal);
    
    int result = numSubarraysWithSum(nums, n, goal);
    printf("%d\n", result);
    
    free(nums);
    return 0;
}
