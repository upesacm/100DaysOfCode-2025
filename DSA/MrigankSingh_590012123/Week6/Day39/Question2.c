#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool is_empty(Stack *s) {
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

int peek(Stack *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack empty\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top];
}

void free_stack(Stack *s) {
    free(s->data);
    s->data = NULL;
    s->top = -1;
    s->capacity = 0;
}

int* stock_span(int prices[], int n) {
    Stack s;
    init_stack(&s, n);
    
    int* result = (int *)malloc(n * sizeof(int));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < n; i++) {
        while (!is_empty(&s) && prices[peek(&s)] <= prices[i]) {
            pop(&s);
        }
        
        if (is_empty(&s)) {
            result[i] = i + 1;
        } else {
            result[i] = i - peek(&s);
        }
        
        push(&s, i);
    }
    
    free_stack(&s);
    return result;
}

int main() {
    int n;
    printf("Enter the number of days: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of days\n");
        return EXIT_FAILURE;
    }
    
    int* prices = (int *)malloc(n * sizeof(int));
    if (prices == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    
    printf("Enter %d stock prices: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &prices[i]) != 1 || prices[i] < 0) {
            fprintf(stderr, "Invalid price input\n");
            free(prices);
            return EXIT_FAILURE;
        }
    }
    
    int* spans = stock_span(prices, n);
    
    printf("Stock spans:\n");
    for (int i = 0; i < n; i++) {
        printf("Day %d: %d\n", i+1, spans[i]);
    }
    
    free(prices);
    free(spans);
    return EXIT_SUCCESS;
}