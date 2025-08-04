#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void push(int stack[], int *top, int val) {
    stack[++(*top)] = val;
}

int pop(int stack[], int *top) {
    return stack[(*top)--];
}

int main() {
    int n, k, val, i;
    int stack[MAX], top = -1;

    printf("Enter number of elements in queue: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    for (i = 0; i < k; i++) push(stack, &top, dequeue());
    for (i = 0; i <= top; i++) enqueue(pop(stack, &top));

    while (front <= rear) {
        printf("%d ", dequeue());
    }

    return 0;
}
