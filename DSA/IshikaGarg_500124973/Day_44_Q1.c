#include <stdio.h>

#define SIZE 100

typedef struct {
    int items[SIZE];
    int front;
    int rear;
} Queue;

// Function to display queue elements without modifying it
void displayQueue(Queue q) {
    if (q.front == -1 || q.front > q.rear) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.items[i]);
    }
    printf("\n");
}
