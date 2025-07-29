#include <stdio.h>
#define MAX 50

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    rear = rear + 1;
    queue[rear] = val;
}

int queueSize() {
    if (front == -1) return 0;
    if (front > rear) return 0;
    return rear - front + 1;
}

int main() {
    int n, val, i;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    printf("Size of queue is: %d\n", queueSize());

    return 0;
}
