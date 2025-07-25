#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *data;
    int top;
    int capacity;
} Stack;

void init_stack(Stack *s, int initial_capacity) {
    s->data = (char *)malloc(initial_capacity * sizeof(char));
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
    s->data = (char *)realloc(s->data, s->capacity * sizeof(char));
    if (s->data == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void push(Stack *s, char c) {
    if (s->top == s->capacity - 1) {
        resize_stack(s);
    }
    s->data[++(s->top)] = c;
}

char pop(Stack *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[(s->top)--];
}

char peek(Stack *s) {
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

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool has_redundant_brackets(const char *expr) {
    Stack s;
    init_stack(&s, strlen(expr));

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == ')') {
            bool has_operator = false;
            char top = pop(&s);

            while (top != '(') {
                if (is_operator(top)) {
                    has_operator = true;
                }
                top = pop(&s);
            }

            if (!has_operator) {
                free_stack(&s);
                return true;
            }
        } else {
            push(&s, expr[i]);
        }
    }

    free_stack(&s);
    return false;
}

int main() {
    char *input = NULL;
    size_t buffer_size = 0;
    ssize_t chars_read;

    printf("Enter a mathematical expression: ");
    chars_read = getline(&input, &buffer_size, stdin);
    
    if (chars_read == -1) {
        fprintf(stderr, "Error reading input\n");
        return EXIT_FAILURE;
    }

    if (chars_read > 0 && input[chars_read - 1] == '\n') {
        input[chars_read - 1] = '\0';
    }

    if (strlen(input) == 0) {
        fprintf(stderr, "Error: Empty expression\n");
        free(input);
        return EXIT_FAILURE;
    }

    bool result = has_redundant_brackets(input);
    printf("%s\n", result ? "Yes" : "No");

    free(input);
    return EXIT_SUCCESS;
}