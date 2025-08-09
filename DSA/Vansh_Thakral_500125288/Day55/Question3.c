#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

typedef struct {
    int key;
    int count;
} FreqMap;

FreqMap freq[SIZE];
int freqSize = 0;

int getCount(int key) {
    for (int i = 0; i < freqSize; i++)
        if (freq[i].key == key)
            return freq[i].count;
    return 0;
}

void addCount(int key, int val) {
    for (int i = 0; i < freqSize; i++) {
        if (freq[i].key == key) {
            freq[i].count += val;
            return;
        }
    }
    freq[freqSize].key = key;
    freq[freqSize].count = val;
    freqSize++;
}

int numSubarraysWithSum(int* nums, int n, int goal) {
    freqSize = 0;
    addCount(0, 1); 

    int sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        count += getCount(sum - goal);
        addCount(sum, 1);
    }
    return count;
}

int main() {
    int nums[] = {1, 0, 1, 0, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int goal = 2;

    printf("%d\n", numSubarraysWithSum(nums, n, goal)); 
    return 0;
}

