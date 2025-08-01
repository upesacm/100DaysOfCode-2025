#include <stdio.h>

#define MAX 100


int insertFront(int queue[], int *size, int element) {
    if (*size >= MAX) {
        printf("Queue Overflow!\n");
        return 0;
    }

    for (int i = *size; i > 0; i--) {
        queue[i] = queue[i - 1];
    }
    queue[0] = element; 
    (*size)++;        
    return 1;
}

int main() {
    int queue[MAX] = {2, 3, 4};
    int size = 3;

    int element = 1;
    insertFront(queue, &size, element);

    printf("Updated Queue (Front Insert): ");
    for (int i = 0; i < size; i++)
        printf("%d ", queue[i]);
    printf("\n");

    return 0;
}

