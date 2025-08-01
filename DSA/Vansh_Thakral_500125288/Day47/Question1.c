#include <stdio.h>

#define MAX 100


int insertRear(int queue[], int *size, int element) {
    if (*size >= MAX) {
        printf("Queue Overflow!\n");
        return 0;
    }
    queue[*size] = element;  
    (*size)++;               
    return 1;
}

int main() {
    int queue[MAX] = {1, 2};
    int size = 2;

    int element = 3;
    insertRear(queue, &size, element);

    printf("Updated Queue (Rear Insert): ");
    for (int i = 0; i < size; i++)
        printf("%d ", queue[i]);
    printf("\n");

    return 0;
}

