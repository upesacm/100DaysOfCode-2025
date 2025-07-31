#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    if (rear < MAX - 1) queue[++rear] = x;
}

int minInQueue() {
    if (front > rear) return 0;
    int m = queue[front];
    for (int i = front + 1; i <= rear; i++)
        if (queue[i] < m) m = queue[i];
    return m;
}

int main() {
    enqueue(4);
    enqueue(2);
    enqueue(7);
    enqueue(1);
    printf("Min: %d\n", minInQueue());
    return 0;
}
