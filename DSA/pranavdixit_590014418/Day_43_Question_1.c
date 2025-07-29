#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void reverseFirstK(int k) {
    int stack[MAX], top = -1;
    for (int i = 0; i < k; i++)
        stack[++top] = dequeue();

    int temp[MAX], t = 0;
    while (top != -1)
        temp[t++] = stack[top--];

    while (front <= rear)
        temp[t++] = dequeue();

    front = 0;
    rear = -1;
    for (int i = 0; i < t; i++)
        enqueue(temp[i]);
}

void printQueue() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    reverseFirstK(3);
    printQueue();
    return 0;
}
