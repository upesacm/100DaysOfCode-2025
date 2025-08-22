#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int key;
    int value;
} Pair;

int find(Pair* map, int size, int key) {
    for (int i = 0; i < size; i++)
        if (map[i].key == key)
            return map[i].value;
    return -1;
}

void insert(Pair* map, int* size, int key, int value) {
    if (find(map, *size, key) == -1) {
        map[*size].key = key;
        map[*size].value = value;
        (*size)++;
    }
}

int longestSubarraySumK(int arr[], int n, int k) {
    Pair map[MAX];
    int mapSize = 0;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == k)
            maxLen = i + 1;

        int prevIndex = find(map, mapSize, sum - k);
        if (prevIndex != -1)
            if (i - prevIndex > maxLen)
                maxLen = i - prevIndex;

        insert(map, &mapSize, sum, i);
    }

    return maxLen;
}

int main() {
    int arr[] = {10, 5, 2, 7, 1, 9};
    int k = 15;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Longest subarray length: %d\n", longestSubarraySumK(arr, n, k)); // Output: 4
    return 0;
}
