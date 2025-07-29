#include <stdio.h>
#include <stdlib.h>

// Node structure for Queue
struct Node {
    int data;
    struct Node* next;
};

// Queue structure with size tracking
struct Queue {
    struct Node *front, *rear;
    int size; // Tracks number of elements
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

// Enqueue operation
void enqueue(struct Queue* q, int data) {
    struct Node* temp = newNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

// Dequeue operation
int dequeue(struct Queue* q) {
    if (q->front == NULL)
        return -1;

    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    q->size--;
    return val;
}

// Function to get size of the queue
int getSize(struct Queue* q) {
    return q->size;
}

// Main function for testing
int main() {
    struct Queue* q = createQueue();

    // Example 1
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    printf("Queue size: %d\n", getSize(q));  // Output: 4

    // Example 2
    struct Queue* q2 = createQueue();
    enqueue(q2, 7);
    printf("Queue size: %d\n", getSize(q2)); // Output: 1

    return 0;
}

