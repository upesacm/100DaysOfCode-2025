#include <stdio.h>
#include <stdlib.h>
typedef struct HashNode 
{
    int key;          
    int value;         
    struct HashNode* next;
} HashNode;
#define TABLE_SIZE 100003  
int hash(int key) 
{
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}
void insert(HashNode* table[], int key, int value) 
{
    int idx = hash(key);
    HashNode* temp = table[idx];
    while (temp) 
    {
        if (temp->key == key) return; 
        temp = temp->next;
    }
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[idx];
    table[idx] = newNode;
}
int search(HashNode* table[], int key, int* found) 
{
    int idx = hash(key);
    HashNode* temp = table[idx];
    while (temp) 
    {
        if (temp->key == key) 
        {
            *found = 1;
            return temp->value;
        }
        temp = temp->next;
    }
    *found = 0;
    return -1;
}
int longestSubarrayWithSumK(int arr[], int n, int k) 
{
    HashNode* hashTable[TABLE_SIZE] = {0};
    int prefixSum = 0, maxLen = 0;
    for (int i = 0; i < n; i++) 
    {
        prefixSum += arr[i];
        if (prefixSum == k) 
        {
            if (i + 1 > maxLen) maxLen = i + 1;
        }
        int found;
        int idx = search(hashTable, prefixSum - k, &found);
        if (found) 
        {
            int len = i - idx;
            if (len > maxLen) maxLen = len;
        }
        insert(hashTable, prefixSum, i);
    }
    return maxLen;
}
int main() 
{
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter target sum k: ");
    scanf("%d", &k);
    int result = longestSubarrayWithSumK(arr, n, k);
    printf("Length of longest subarray with sum %d = %d\n", k, result);
    return 0;
}
