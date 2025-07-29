#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        perror("Failed to allocate memory for Queue");
        exit(EXIT_FAILURE);
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for Node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue* q, int data) {
    Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
    printf("Enqueued: %d\n", data);
}

void displayQueue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements (front to rear): ");
    Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void destroyQueue(Queue* q) {
    Node* current = q->front;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(q);
}

int main() {
    printf("--- Display Elements of a Queue with User Input ---\n");
    Queue* userQueue = createQueue();
    int numElements;
    int data;

    printf("Enter the number of elements to enqueue: ");
    if (scanf("%d", &numElements) != 1 || numElements < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        destroyQueue(userQueue);
        return 1;
    }

    printf("Enter %d integer elements:\n", numElements);
    for (int i = 0; i < numElements; i++) {
        printf("Element %d: ", i + 1);
        if (scanf("%d", &data) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            break;
        }
        enqueue(userQueue, data);
    }

    printf("\n--- Displaying the queue you created ---\n");
    displayQueue(userQueue);
    printf("Original queue after display (should be unchanged):\n");
    displayQueue(userQueue);

    destroyQueue(userQueue);

    return 0;
}
