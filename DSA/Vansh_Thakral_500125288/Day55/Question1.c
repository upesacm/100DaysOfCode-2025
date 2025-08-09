#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

typedef struct {
    int key;
    int value;
} MapEntry;

MapEntry map[SIZE];
int mapSize = 0;

int findInMap(int key) {
    for (int i = 0; i < mapSize; i++)
        if (map[i].key == key)
            return map[i].value;
    return -1;
}

void insertInMap(int key, int value) {
    if (findInMap(key) == -1) {
        map[mapSize].key = key;
        map[mapSize].value = value;
        mapSize++;
    }
}

int longestSubarraySumK(int* arr, int n, int k) {
    int prefixSum = 0, maxLen = 0;
    mapSize = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == k)
            maxLen = i + 1;

        int idx = findInMap(prefixSum - k);
        if (idx != -1)
            if (i - idx > maxLen)
                maxLen = i - idx;

        insertInMap(prefixSum, i);
    }
    return maxLen;
}

int main() {
    int arr[] = {10, 5, 2, 7, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 15;

    printf("%d\n", longestSubarraySumK(arr, n, k)); 
    return 0;
}

