#include <stdio.h>
#include <limits.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
int isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int val = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return val;
}

int findMinimum() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return -1;
    }

    int size = rear - front + 1;
    int min = INT_MAX;

    for (int i = 0; i < size; i++) {
        int val = dequeue();
        if (val < min)
            min = val;
        enqueue(val); 
    }

    return min;
}

int main() {
    int n, value;

    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    int min = findMinimum();
    printf("Minimum element in the queue: %d\n", min);

    return 0;
}
