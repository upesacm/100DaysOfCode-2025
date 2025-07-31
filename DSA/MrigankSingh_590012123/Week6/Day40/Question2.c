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

int largest_rectangle_area(int *heights, int n) {
    Stack s;
    init_stack(&s, n);
    
    int *extended_heights = (int *)malloc((n + 1) * sizeof(int));
    if (extended_heights == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        extended_heights[i] = heights[i];
    }
    extended_heights[n] = 0;

    int max_area = 0;

    for (int i = 0; i <= n; i++) {
        while (!is_empty(&s) && extended_heights[i] < extended_heights[peek(&s)]) {
            int height = extended_heights[pop(&s)];
            int width = is_empty(&s) ? i : (i - peek(&s) - 1);
            int area = height * width;
            if (area > max_area) {
                max_area = area;
            }
        }
        push(&s, i);
    }

    free(extended_heights);
    free_stack(&s);
    return max_area;
}

int main() {
    int n;
    printf("Enter the number of bars: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of bars\n");
        return EXIT_FAILURE;
    }

    int *heights = (int *)malloc(n * sizeof(int));
    if (heights == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    printf("Enter %d non-negative heights: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &heights[i]) != 1 || heights[i] < 0) {
            fprintf(stderr, "Invalid height input\n");
            free(heights);
            return EXIT_FAILURE;
        }
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    int result = largest_rectangle_area(heights, n);
    printf("Largest rectangle area: %d\n", result);

    free(heights);
    return EXIT_SUCCESS;
}