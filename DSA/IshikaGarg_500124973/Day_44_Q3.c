#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for queue
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create a new empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
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
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Main function for testing
int main() {
    struct Queue* q1 = createQueue();

    // Example 1: Empty queue
    if (isEmpty(q1))
        printf("Queue is empty: True\n");  // Output: True
    else
        printf("Queue is empty: False\n");

    // Example 2: Queue with elements
    enqueue(q1, 1);
    enqueue(q1, 2);
    
    if (isEmpty(q1))
        printf("Queue is empty: True\n");
    else
        printf("Queue is empty: False\n"); // Output: False

    return 0;
}
