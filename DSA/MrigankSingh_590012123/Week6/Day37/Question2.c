#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

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

int evaluate_postfix(const char *expr) {
    Stack s;
    init_stack(&s, 16);
    
    int i = 0;
    while (expr[i] != '\0') {
        if (isspace(expr[i])) {
            i++;
            continue;
        }

        if (expr[i] == '-' && isdigit(expr[i+1])) {
            i++;
            int num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            push(&s, -num);
        }
        else if (isdigit(expr[i])) {
            int num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            push(&s, num);
        }
        else if (expr[i] == '+' || expr[i] == '-' || 
                 expr[i] == '*' || expr[i] == '/') {
            if (s.top < 1) {
                fprintf(stderr, "Error: Not enough operands for operator '%c'\n", expr[i]);
                free_stack(&s);
                return INT_MIN;
            }
            
            int b = pop(&s);
            int a = pop(&s);
            int result;
            
            switch (expr[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': 
                    if (b == 0) {
                        fprintf(stderr, "Error: Division by zero\n");
                        free_stack(&s);
                        return INT_MIN;
                    }
                    result = a / b; 
                    break;
                default:
                    fprintf(stderr, "Error: Unknown operator '%c'\n", expr[i]);
                    free_stack(&s);
                    return INT_MIN;
            }
            push(&s, result);
            i++;
        } else {
            fprintf(stderr, "Error: Invalid character '%c' in expression\n", expr[i]);
            free_stack(&s);
            return INT_MIN;
        }
    }

    if (s.top != 0) {
        fprintf(stderr, "Error: Invalid expression format\n");
        free_stack(&s);
        return INT_MIN;
    }

    int final_result = pop(&s);
    free_stack(&s);
    return final_result;
}

int main() {
    char *input = NULL;
    size_t buffer_size = 0;
    ssize_t chars_read;

    printf("Enter a postfix expression: ");
    chars_read = getline(&input, &buffer_size, stdin);
    
    if (chars_read == -1) {
        fprintf(stderr, "Error reading input\n");
        free(input);
        return EXIT_FAILURE;
    }

    if (chars_read > 0 && input[chars_read - 1] == '\n') {
        input[chars_read - 1] = '\0';
    }

    int result = evaluate_postfix(input);
    if (result == INT_MIN) {
        free(input);
        return EXIT_FAILURE;
    }

    printf("Result: %d\n", result);
    free(input);
    return EXIT_SUCCESS;
}