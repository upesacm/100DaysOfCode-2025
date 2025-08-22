#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 1000

typedef struct Node {
    int sum;
    int freq;
    struct Node* next;
} Node;

Node* hashTable[HASH_SIZE];


int hash(int key) {
    return abs(key) % HASH_SIZE;
}


void increment(int sum) {
    int h = hash(sum);
    Node* curr = hashTable[h];
    while (curr) {
        if (curr->sum == sum) {
            curr->freq++;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->freq = 1;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}


int getFreq(int sum) {
    int h = hash(sum);
    Node* curr = hashTable[h];
    while (curr) {
        if (curr->sum == sum) return curr->freq;
        curr = curr->next;
    }
    return 0;
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


int countSubarraysWithSum(int* nums, int n, int goal) {
    clearHash();
    int count = 0;
    int sum = 0;

    increment(0);  

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        count += getFreq(sum - goal);
        increment(sum);
    }

    return count;
}

int main() {
    
    int nums1[] = {1, 0, 1, 0, 1};
    int goal1 = 2;
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Subarrays with sum %d: %d\n", goal1, countSubarraysWithSum(nums1, n1, goal1));  // ➜ 4

    
    int nums2[] = {0, 0, 0, 0, 0};
    int goal2 = 0;
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Subarrays with sum %d: %d\n", goal2, countSubarraysWithSum(nums2, n2, goal2));  // ➜ 15

    return 0;
}
