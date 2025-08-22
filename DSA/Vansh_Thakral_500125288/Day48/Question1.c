#include <stdio.h>

#define MAX 100


int removeOccurrences(int queue[], int *size, int x) {
    int newSize = 0;

    for (int i = 0; i < *size; i++) {
        if (queue[i] != x) { 
            queue[newSize++] = queue[i]; 
        }
    }

    *size = newSize; 
    return 1;
}

int main() {
    int queue[MAX] = {1, 2, 3, 2, 4};
    int size = 5;
    int x = 2;

    removeOccurrences(queue, &size, x);

    printf("Updated Queue after removing %d: ", x);
    for (int i = 0; i < size; i++)
        printf("%d ", queue[i]);
    printf("\n");

    return 0;
}

