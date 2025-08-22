#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// --- Data Structure & Helpers for Queue ---

typedef struct {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

bool isQueueEmpty(Queue* queue) { return (queue->size == 0); }
bool isQueueFull(Queue* queue) { return (queue->size == queue->capacity); }

void enqueue(Queue* queue, int item) {
    if (isQueueFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

void printQueue(const char* label, Queue* queue) {
    printf("%s", label);
    if (isQueueEmpty(queue)) {
        printf("[]\n");
        return;
    }
    printf("[");
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % queue->capacity;
        printf("%d", queue->array[index]);
        if (i < queue->size - 1) printf(", ");
    }
    printf("]\n");
}


// --- Data Structure & Helpers for Stack ---

typedef struct {
    int top;
    unsigned capacity;
    int* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

bool isStackEmpty(Stack* stack) { return stack->top == -1; }
bool isStackFull(Stack* stack) { return stack->top == stack->capacity - 1; }
void push(Stack* stack, int item) { if (!isStackFull(stack)) stack->array[++stack->top] = item; }
int pop(Stack* stack) { if (!isStackEmpty(stack)) return stack->array[stack->top--]; return INT_MIN; }


// --- Core Logic ---

/**
 * Checks if the sequence of elements in a queue forms a palindrome.
 * Note: This function preserves the original queue.
 */
bool isQueuePalindrome(Queue* queue) {
    if (isQueueEmpty(queue)) return true;

    Stack* stack = createStack(queue->capacity);
    int n = queue->size;
    bool isPalindrome = true;

    // Dequeue all items from queue and push to stack, then re-enqueue.
    // This populates the stack and preserves the queue's contents.
    for (int i = 0; i < n; i++) {
        int item = dequeue(queue);
        push(stack, item);
        enqueue(queue, item);
    }
    
    // Dequeue again, but this time compare with popped stack items.
    // Re-enqueue to restore the queue to its final original state.
    for (int i = 0; i < n; i++) {
        int queue_item = dequeue(queue);
        int stack_item = pop(stack);

        if (queue_item != stack_item) {
            isPalindrome = false;
        }
        enqueue(queue, queue_item);
    }

    free(stack->array);
    free(stack);
    return isPalindrome;
}


int main() {
    Queue* q_p1 = createQueue(10);
    enqueue(q_p1, 1);
    enqueue(q_p1, 2);
    enqueue(q_p1, 3);
    enqueue(q_p1, 2);
    enqueue(q_p1, 1);
    
    printQueue("Test Queue 1: ", q_p1);
    printf("Is it a palindrome? %s\n", isQueuePalindrome(q_p1) ? "Yes" : "No");
    printQueue("Queue 1 after check: ", q_p1); // Verify it's unchanged

    printf("\n");

    Queue* q_p2 = createQueue(10);
    enqueue(q_p2, 1);
    enqueue(q_p2, 2);
    enqueue(q_p2, 3);
    
    printQueue("Test Queue 2: ", q_p2);
    printf("Is it a palindrome? %s\n", isQueuePalindrome(q_p2) ? "Yes" : "No");
    printQueue("Queue 2 after check: ", q_p2); // Verify it's unchanged

    // Free memory
    free(q_p1->array);
    free(q_p1);
    free(q_p2->array);
    free(q_p2);

    return 0;
}