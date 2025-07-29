#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Define the Queue structure
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(Queue *q) {
    return (q->rear < q->front);
}

// Function to enqueue
void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    q->items[++(q->rear)] = value;
}

// Example usage
int main() {
    Queue q;
    initQueue(&q);

    printf("Is queue empty? %s\n", isEmpty(&q) ? "True" : "False");

    enqueue(&q, 1);
    enqueue(&q, 2);

    printf("Is queue empty? %s\n", isEmpty(&q) ? "True" : "False");

    return 0;
}
