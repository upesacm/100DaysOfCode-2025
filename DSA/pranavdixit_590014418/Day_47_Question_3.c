#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    if (rear < MAX - 1)
        queue[++rear] = x;
}

void findFrontRear() {
    if (front > rear)
        printf("Queue is empty\n");
    else
        printf("Front: %d, Rear: %d\n", queue[front], queue[rear]);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    findFrontRear();  // Output: Front: 10, Rear: 30
    return 0;
}
