#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 50, rear = 49;  // start from middle

void enqueueFront(int x) {
    if (front > 0)
        queue[--front] = x;
}

void enqueueRear(int x) {
    if (rear < MAX - 1)
        queue[++rear] = x;
}

void printQueue() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueueRear(2);
    enqueueRear(3);
    enqueueRear(4);
    enqueueFront(1);
    printQueue();  // Output: 1 2 3 4
    return 0;
}
