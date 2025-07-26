#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int *stack;
    int *max_stack;
    int top;
    int capacity;
} MaxStack;

void maxStackCreate(MaxStack *ms, int initial_capacity) {
    ms->stack = (int *)malloc(initial_capacity * sizeof(int));
    ms->max_stack = (int *)malloc(initial_capacity * sizeof(int));
    if (ms->stack == NULL || ms->max_stack == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    ms->top = -1;
    ms->capacity = initial_capacity;
}

bool isEmpty(MaxStack *ms) {
    return ms->top < 0;
}

void resize(MaxStack *ms) {
    ms->capacity *= 2;
    ms->stack = (int *)realloc(ms->stack, ms->capacity * sizeof(int));
    ms->max_stack = (int *)realloc(ms->max_stack, ms->capacity * sizeof(int));
    if (ms->stack == NULL || ms->max_stack == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void maxStackPush(MaxStack *ms, int x) {
    if (ms->top == ms->capacity - 1) {
        resize(ms);
    }
    ms->stack[++(ms->top)] = x;
    if (ms->top == 0) {
        ms->max_stack[ms->top] = x;
    } else {
        ms->max_stack[ms->top] = (x > ms->max_stack[ms->top - 1]) ? x : ms->max_stack[ms->top - 1];
    }
}

int maxStackPop(MaxStack *ms) {
    if (isEmpty(ms)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return ms->stack[(ms->top)--];
}

int maxStackTop(MaxStack *ms) {
    if (isEmpty(ms)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return ms->stack[ms->top];
}

int maxStackGetMax(MaxStack *ms) {
    if (isEmpty(ms)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return ms->max_stack[ms->top];
}

void maxStackFree(MaxStack *ms) {
    free(ms->stack);
    free(ms->max_stack);
    ms->stack = NULL;
    ms->max_stack = NULL;
    ms->top = -1;
    ms->capacity = 0;
}

void showMenu() {
    printf("\n=== Max Stack Menu ===\n");
    printf("1. Push <x>\n");
    printf("2. Pop\n");
    printf("3. Top\n");
    printf("4. Get Max\n");
    printf("5. Quit\n");
    printf("======================\n");
    printf("Enter your choice: ");
}

int main() {
    MaxStack ms;
    maxStackCreate(&ms, 4);
    int choice, value;
    bool running = true;

    while (running) {
        showMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid number\n");
                    break;
                }
                maxStackPush(&ms, value);
                printf("Pushed %d\n", value);
                break;

            case 2:
                if (!isEmpty(&ms)) {
                    printf("Popped %d\n", maxStackPop(&ms));
                } else {
                    printf("Stack is empty\n");
                }
                break;

            case 3:
                if (!isEmpty(&ms)) {
                    printf("Top: %d\n", maxStackTop(&ms));
                } else {
                    printf("Stack is empty\n");
                }
                break;

            case 4:
                if (!isEmpty(&ms)) {
                    printf("Max: %d\n", maxStackGetMax(&ms));
                } else {
                    printf("Stack is empty\n");
                }
                break;

            case 5:
                running = false;
                break;

            default:
                printf("Unknown choice. Please select between 1-5.\n");
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    maxStackFree(&ms);
    printf("Exiting program.\n");
    return 0;
}
