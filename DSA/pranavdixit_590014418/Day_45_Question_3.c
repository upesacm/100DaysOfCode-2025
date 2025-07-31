#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int maxInQueue() {
    int max = queue[front];
    for (int i = front + 1; i <= rear; i++) {
        if (queue[i] > max)
            max = queue[i];
    }
    return max;
}

int main() {
    enqueue(3);
    enqueue(5);
    enqueue(1);
    enqueue(2);

    int result = maxInQueue();
    printf("Max: %d\n", result);
    return 0;
}
