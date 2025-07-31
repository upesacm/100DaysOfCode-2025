#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    if (rear < MAX - 1)
        queue[++rear] = x;
}

int sumOfQueue() {
    int sum = 0;
    for (int i = front; i <= rear; i++)
        sum += queue[i];
    return sum;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);

    int result = sumOfQueue();
    printf("Sum: %d\n", result);
    return 0;
}
