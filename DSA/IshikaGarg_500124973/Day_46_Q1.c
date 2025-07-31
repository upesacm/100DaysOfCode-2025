#include <stdio.h>
#define SIZE 100

// Queue definition
int queue[SIZE], front = -1, rear = -1;

// Enqueue operation
void enqueue(int val) {
    if (rear == SIZE - 1)
        printf("Queue is full\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = val;
    }
}

// Display queue without altering it
void displayQueue() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

// Function to find minimum element
int findMinimum() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int min = queue[front];
    for (int i = front + 1; i <= rear; i++) {
        if (queue[i] < min)
            min = queue[i];
    }
    return min;
}

int main() {
    // Input: [4, 2, 7, 1]
    enqueue(4);
    enqueue(2);
    enqueue(7);
    enqueue(1);

    printf("Queue elements: ");
    displayQueue();

    int min = findMinimum();
    printf("Minimum element in queue: %d\n", min);

    return 0;
}

