#include <stdio.h>

#define MAX 100
#define MAX_VAL 100  // Assuming elements are in range 0-99

void countOccurrences(int queue[], int size) {
    int freq[MAX_VAL] = {0};

    
    for (int i = 0; i < size; i++) {
        freq[queue[i]]++;
    }

    printf("Frequency of elements:\n");
    for (int i = 0; i < MAX_VAL; i++) {
        if (freq[i] > 0) {
            printf("%d: %d\n", i, freq[i]);
        }
    }
}

int main() {
    int queue[] = {1, 2, 2, 3, 1, 1};
    int size = 6;

    countOccurrences(queue, size);

    return 0;
}

