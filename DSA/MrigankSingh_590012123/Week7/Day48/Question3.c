#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

typedef struct Frequency {
    int value;
    int count;
} Frequency;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return -1; 
    }
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return data;
}

bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}

Frequency* countOccurrences(Queue* queue, int* uniqueCount) {
    if (isEmpty(queue)) {
        *uniqueCount = 0;
        return NULL;
    }

    int* elements = (int*)malloc(queue->size * sizeof(int));
    if (!elements) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    Queue* tempQueue = createQueue();
    int index = 0;

    while (!isEmpty(queue)) {
        int val = dequeue(queue);
        elements[index++] = val;
        enqueue(tempQueue, val);
    }

    while (!isEmpty(tempQueue)) {
        enqueue(queue, dequeue(tempQueue));
    }
    freeQueue(tempQueue);

    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (elements[i] > elements[j]) {
                int temp = elements[i];
                elements[i] = elements[j];
                elements[j] = temp;
            }
        }
    }

    Frequency* frequencies = NULL;
    *uniqueCount = 0;
    int current = elements[0];
    int count = 1;

    for (int i = 1; i < index; i++) {
        if (elements[i] == current) {
            count++;
        } else {
            frequencies = realloc(frequencies, (*uniqueCount + 1) * sizeof(Frequency));
            frequencies[*uniqueCount].value = current;
            frequencies[*uniqueCount].count = count;
            (*uniqueCount)++;
            current = elements[i];
            count = 1;
        }
    }

    frequencies = realloc(frequencies, (*uniqueCount + 1) * sizeof(Frequency));
    frequencies[*uniqueCount].value = current;
    frequencies[*uniqueCount].count = count;
    (*uniqueCount)++;

    free(elements);
    return frequencies;
}

void printFrequencies(Frequency* freq, int uniqueCount) {
    printf("{");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%d: %d", freq[i].value, freq[i].count);
        if (i < uniqueCount - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void freeQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

void readQueueInput(Queue* queue) {
    int n, data;
    printf("Enter the number of elements in the queue: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Error: Invalid number of elements.\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &data) != 1) {
            printf("Error: Invalid input.\n");
            exit(EXIT_FAILURE);
        }
        enqueue(queue, data);
    }
}

int main() {
    Queue* queue = createQueue();
    readQueueInput(queue);

    printf("\nQueue contents: ");
    Node* current = queue->front;
    printf("[");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");

    int uniqueCount;
    Frequency* frequencies = countOccurrences(queue, &uniqueCount);

    printf("Frequency distribution: ");
    printFrequencies(frequencies, uniqueCount);

    free(frequencies);
    freeQueue(queue);
    return 0;
}
