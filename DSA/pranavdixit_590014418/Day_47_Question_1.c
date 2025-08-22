#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

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
    enqueueRear(1);
    enqueueRear(2);
    enqueueRear(3);
    printQueue();  // Output: 1 2 3
    return 0;
}
