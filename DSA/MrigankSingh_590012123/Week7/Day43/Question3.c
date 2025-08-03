#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char *data;
    int capacity;
    int front;
    int rear;
    int size;
} Queue;

typedef struct {
    char *data;
    int capacity;
    int top;
} Stack;

Queue* init_queue(int capacity) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if (!q) return NULL;
    q->data = (char*)malloc(capacity * sizeof(char));
    if (!q->data) {
        free(q);
        return NULL;
    }
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

bool is_empty_queue(Queue *q) {
    return q->size == 0;
}

bool is_full_queue(Queue *q) {
    return q->size == q->capacity;
}

bool enqueue(Queue *q, char x) {
    if (is_full_queue(q)) return false;
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = x;
    q->size++;
    return true;
}

bool dequeue(Queue *q, char *x) {
    if (is_empty_queue(q)) return false;
    *x = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return true;
}

void free_queue(Queue *q) {
    if (!q) return;
    free(q->data);
    free(q);
}

Stack* init_stack(int capacity) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if (!s) return NULL;
    s->data = (char*)malloc(capacity * sizeof(char));
    if (!s->data) {
        free(s);
        return NULL;
    }
    s->capacity = capacity;
    s->top = -1;
    return s;
}

bool is_empty_stack(Stack *s) {
    return s->top < 0;
}

bool push(Stack *s, char x) {
    if (s->top >= s->capacity - 1) return false;
    s->data[++(s->top)] = x;
    return true;
}

bool pop(Stack *s, char *x) {
    if (is_empty_stack(s)) return false;
    *x = s->data[(s->top)--];
    return true;
}

void free_stack(Stack *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

bool is_queue_palindrome(Queue *q) {
    if (is_empty_queue(q)) return true;

    int original_size = q->size;
    Stack *s = init_stack(original_size);
    if (!s) return false;

    for (int i = 0; i < original_size; i++) {
        char x;
        dequeue(q, &x);
        push(s, x);
        enqueue(q, x);
    }

    for (int i = 0; i < original_size / 2; i++) {
        char q_char, s_char;
        dequeue(q, &q_char);
        pop(s, &s_char);
        if (q_char != s_char) {
            free_stack(s);
            return false;
        }
        enqueue(q, q_char);
    }

    free_stack(s);
    return true;
}

void print_queue(Queue *q) {
    printf("[");
    for (int i = 0, index = q->front; i < q->size; i++, index = (index + 1) % q->capacity) {
        printf("'%c'", q->data[index]);
        if (i < q->size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n;
    printf("Enter the number of characters in the queue: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Error: Invalid number of characters.\n");
        return 1;
    }

    Queue *q = init_queue(n);
    if (!q) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d characters for the queue: ", n);
    for (int i = 0; i < n; i++) {
        char x;
        if (scanf(" %c", &x) != 1) {
            printf("Error: Invalid character input.\n");
            free_queue(q);
            return 1;
        }
        if (!enqueue(q, x)) {
            printf("Error: Queue overflow.\n");
            free_queue(q);
            return 1;
        }
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    bool result = is_queue_palindrome(q);

    printf("%s\n", result ? "Yes" : "No");

    free_queue(q);

    return 0;
}
