#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

void init_stack(Stack *s, int initial_capacity) {
    s->data = (int *)malloc(initial_capacity * sizeof(int));
    if (s->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    s->top = -1;
    s->capacity = initial_capacity;
}

int is_empty(Stack *s) {
    return s->top < 0;
}

void resize_stack(Stack *s) {
    s->capacity *= 2;
    s->data = (int *)realloc(s->data, s->capacity * sizeof(int));
    if (s->data == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void push(Stack *s, int x) {
    if (s->top == s->capacity - 1) {
        resize_stack(s);
    }
    s->data[++(s->top)] = x;
}

int pop(Stack *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[(s->top)--];
}

void free_stack(Stack *s) {
    free(s->data);
    s->data = NULL;
    s->top = -1;
    s->capacity = 0;
}

void insert_at_bottom(Stack *s, int x) {
    if (is_empty(s)) {
        push(s, x);
        return;
    }

    int top_element = pop(s);
    insert_at_bottom(s, x);
    push(s, top_element);
}

void print_stack(Stack *s) {
    printf("[");
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->data[i]);
        if (i < s->top) printf(", ");
    }
    printf("]\n");
}

int main() {
    Stack s;
    int n, x;

    printf("Enter the number of elements in the stack: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Error: Invalid number of elements.\n");
        return 1;
    }

    init_stack(&s, n > 0 ? n : 1);

    printf("Enter %d integers for the stack: ", n);
    for (int i = 0; i < n; i++) {
        int value;
        if (scanf("%d", &value) != 1) {
            printf("Error: Invalid integer input.\n");
            free_stack(&s);
            return 1;
        }
        push(&s, value);
    }

    printf("Enter the element to insert at bottom: ");
    if (scanf("%d", &x) != 1) {
        printf("Error: Invalid integer input for x.\n");
        free_stack(&s);
        return 1;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    insert_at_bottom(&s, x);
    print_stack(&s);

    free_stack(&s);
    return 0;
}