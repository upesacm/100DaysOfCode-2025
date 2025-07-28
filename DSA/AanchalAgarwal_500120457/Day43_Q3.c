#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
typedef struct {
    char items[MAX];
    int front, rear;
} Queue;

// Stack structure
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Queue functions
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue *q, char value) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow\n");
        exit(1);
    }
    q->items[++(q->rear)] = value;
}

char dequeue(Queue *q) {
    if (q->front > q->rear) {
        printf("Queue underflow\n");
        exit(1);
    }
    return q->items[(q->front)++];
}

// Stack functions
void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char value) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// Palindrome check function
const char* isPalindrome(char arr[], int size) {
    Queue q;
    Stack s;
    initQueue(&q);
    initStack(&s);

    // Step 1: Push and Enqueue all characters
    for (int i = 0; i < size; i++) {
        enqueue(&q, arr[i]);
        push(&s, arr[i]);
    }

    // Step 2: Compare elements
    for (int i = 0; i < size; i++) {
        char fromQueue = dequeue(&q);
        char fromStack = pop(&s);
        if (fromQueue != fromStack) {
            return "No";
        }
    }

    return "Yes";
}

// 🔍 Example usage
int main() {
    char input1[] = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};
    char input2[] = {'a', 'b', 'c'};

    int size1 = sizeof(input1) / sizeof(input1[0]);
    int size2 = sizeof(input2) / sizeof(input2[0]);

    printf("Is input1 a palindrome? %s\n", isPalindrome(input1, size1));  // Yes
    printf("Is input2 a palindrome? %s\n", isPalindrome(input2, size2));  // No

    return 0;
}
