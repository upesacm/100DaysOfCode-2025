
#include<stdio.h>
#include<stdlib.h>
typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    char* array;
} Queue;
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (char*)malloc(queue->capacity * sizeof(char));
    return queue;
}
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}
void enqueue(Queue* queue, char item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}
char dequeue(Queue* queue) {
    if (isEmpty(queue)) return '\0';
    char item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}
typedef struct Stack {
    int top;
    unsigned capacity;
    char* array;
} Stack;
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}
int isStackFull(Stack* stack) {
    return (stack->top == stack->capacity - 1);
}
int isStackEmpty(Stack* stack) {
    return (stack->top == -1);
}
void push(Stack* stack, char item) {
    if (isStackFull(stack)) return;
    stack->array[++stack->top] = item;
}
char pop(Stack* stack) {
    if (isStackEmpty(stack)) return '\0';
    return stack->array[stack->top--];
}
int isPalindrome(Queue* queue) {
    Stack* stack = createStack(queue->size);
    int originalSize = queue->size;
    for (int i = 0; i < originalSize; i++) {
        char item = dequeue(queue);
        push(stack, item);
        enqueue(queue, item);
    }
    for (int i = 0; i < originalSize; i++) {
        char queueChar = dequeue(queue);
        char stackChar = pop(stack);
        if (queueChar != stackChar) {
            free(stack->array);
            free(stack);
            return 0;
        }
    }
    free(stack->array);
    free(stack);
    return 1;
}
int main() {
    Queue* queue = createQueue(7);
    char input[] = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};
    for (int i = 0; i < 7; i++) {
        enqueue(queue, input[i]);
    }
    if (isPalindrome(queue)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    free(queue->array);
    free(queue);
    return 0;
}
