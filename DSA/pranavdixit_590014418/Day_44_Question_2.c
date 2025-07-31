#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    if (rear < MAX - 1)
        queue[++rear] = x;
}

int queueSize() {
    return (rear - front + 1);
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    int size = queueSize();
    printf("Queue Size: %d\n", size);
    return 0;
}
