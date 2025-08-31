#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 256
typedef struct 
{
    char ch;
    int freq;
} CharFreq;
void swap(CharFreq *a, CharFreq *b) 
{
    CharFreq temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(CharFreq heap[], int n, int i) 
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && heap[left].freq > heap[largest].freq)
        largest = left;
    if (right < n && heap[right].freq > heap[largest].freq)
        largest = right;
    if (largest != i) 
    {
        swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}
CharFreq extractMax(CharFreq heap[], int *n) 
{
    CharFreq root = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapify(heap, *n, 0);
    return root;
}
void insertHeap(CharFreq heap[], int *n, CharFreq item) 
{
    heap[*n] = item;
    int i = (*n)++;
    while (i > 0 && heap[(i-1)/2].freq < heap[i].freq) 
    {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}
bool rearrangeString(char *str, char *result) 
{
    int len = strlen(str);
    int freq[MAX] = {0};
    for (int i = 0; i < len; i++)
        freq[(int)str[i]]++;
    CharFreq heap[MAX];
    int heapSize = 0;
    for (int i = 0; i < MAX; i++) 
    {
        if (freq[i] > 0) 
        {
            heap[heapSize].ch = (char)i;
            heap[heapSize].freq = freq[i];
            heapSize++;
        }
    }
    for (int i = heapSize/2 - 1; i >= 0; i--)
        heapify(heap, heapSize, i);

    CharFreq prev = {'#', 0}; 
    int idx = 0;
    while (heapSize > 0) 
    {
        CharFreq curr = extractMax(heap, &heapSize);
        result[idx++] = curr.ch;
        curr.freq--;
        if (prev.freq > 0)
            insertHeap(heap, &heapSize, prev);
        prev = curr;
    }
    result[idx] = '\0';
    if (idx != len)
        return false;
    return true;
}
int main() 
{
    char str[] = "aaabbc";
    char result[100];

    if (rearrangeString(str, result))
        printf("Rearranged string: %s\n", result);
    else
        printf("Not possible to rearrange without adjacent duplicates.\n");

    return 0;
}
