#include <stdio.h>
#include <stdlib.h>

// Hash map node
typedef struct {
    int sum;
    int index;
} MapEntry;

// Simple hash function for int keys
#define MAP_SIZE 100003
int hashFunc(int key) {
    if (key < 0) key = -key;
    return key % MAP_SIZE;
}

void insert(MapEntry *map, int sum, int index) {
    int h = hashFunc(sum);
    while (map[h].sum != 2147483647) { // empty slot indicator
        h = (h + 1) % MAP_SIZE;
    }
    map[h].sum = sum;
    map[h].index = index;
}

int search(MapEntry *map, int sum) {
    int h = hashFunc(sum);
    while (map[h].sum != 2147483647) {
        if (map[h].sum == sum)
            return map[h].index;
        h = (h + 1) % MAP_SIZE;
    }
    return -1; // not found
}

int longestSubarraySumK(int arr[], int n, int k) {
    MapEntry *map = malloc(sizeof(MapEntry) * MAP_SIZE);
    for (int i = 0; i < MAP_SIZE; i++) {
        map[i].sum = 2147483647; // empty slot
        map[i].index = -1;
    }

    int prefix_sum = 0;
    int max_len = 0;

    // store prefix sum 0 at index -1
    insert(map, 0, -1);

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        int needed = prefix_sum - k;
        int foundIndex = search(map, needed);
        if (foundIndex != -1) {
            int length = i - foundIndex;
            if (length > max_len) max_len = length;
        }

        // store first occurrence of prefix sum
        if (search(map, prefix_sum) == -1) {
            insert(map, prefix_sum, i);
        }
    }

    free(map);
    return max_len;
}

int main() {
    int arr[] = {10, 5, 2, 7, 1, 9};
    int k = 15;
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Longest Subarray Length = %d\n", longestSubarraySumK(arr, n, k));
    return 0;
}

