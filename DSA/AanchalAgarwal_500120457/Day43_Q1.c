#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Queue operations
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isQueueEmpty(Queue *q) {
    return q->front > q->rear;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    q->items[++(q->rear)] = value;
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue underflow\n");
        exit(1);
    }
    return q->items[(q->front)++];
}

// Stack operations
void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// Reverse first k elements
void reverseFirstKElements(Queue *q, int k) {
    if (k > (q->rear - q->front + 1) || k < 0) {
        printf("Invalid value of k\n");
        return;
    }

    Stack s;
    initStack(&s);

    // Step 1: Push first k elements into the stack
    for (int i = 0; i < k; i++) {
        push(&s, dequeue(q));
    }

    // Step 2: Enqueue back stack elements
    while (!isStackEmpty(&s)) {
        enqueue(q, pop(&s));
    }

    // Step 3: Move the remaining elements to the back of the queue
    int remaining = q->rear - q->front + 1 - k;
    for (int i = 0; i < remaining; i++) {
        enqueue(q, dequeue(q));
    }
}

// Helper to print queue
void printQueue(Queue *q) {
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// 🔍 Example usage
int main() {
    Queue q;
    initQueue(&q);

    // Sample input
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    int k = 3;

    printf("Original Queue: ");
    printQueue(&q);

    reverseFirstKElements(&q, k);

    printf("Queue after reversing first %d elements: ", k);
    printQueue(&q);

    return 0;
}
