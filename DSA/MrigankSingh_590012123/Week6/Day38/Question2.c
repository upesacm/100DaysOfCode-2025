#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int *stack;
    int *min_stack;
    int top;
    int capacity;
} MinStack;

void minStackCreate(MinStack *ms, int initial_capacity) {
    ms->stack = (int *)malloc(initial_capacity * sizeof(int));
    ms->min_stack = (int *)malloc(initial_capacity * sizeof(int));
    if (ms->stack == NULL || ms->min_stack == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    ms->top = -1;
    ms->capacity = initial_capacity;
}

int isEmpty(MinStack *ms) {
    return ms->top < 0;
}

void resizeStack(MinStack *ms) {
    ms->capacity *= 2;
    ms->stack = (int *)realloc(ms->stack, ms->capacity * sizeof(int));
    ms->min_stack = (int *)realloc(ms->min_stack, ms->capacity * sizeof(int));
    if (ms->stack == NULL || ms->min_stack == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void minStackPush(MinStack *ms, int x) {
    if (ms->top == ms->capacity - 1) {
        resizeStack(ms);
    }
    ms->stack[++(ms->top)] = x;
    if (ms->top == 0) {
        ms->min_stack[ms->top] = x;
    } else {
        ms->min_stack[ms->top] = (x < ms->min_stack[ms->top - 1]) ? x : ms->min_stack[ms->top - 1];
    }
}

int minStackPop(MinStack *ms) {
    if (isEmpty(ms)) {
        fprintf(stderr, "Stack underflow\n");
        return 0;
    }
    ms->top--;
    return 1;
}

int minStackTop(MinStack *ms) {
    if (isEmpty(ms)) {
        fprintf(stderr, "Stack is empty\n");
        return INT_MIN;
    }
    return ms->stack[ms->top];
}

int minStackGetMin(MinStack *ms) {
    if (isEmpty(ms)) {
        fprintf(stderr, "Stack is empty\n");
        return INT_MIN;
    }
    return ms->min_stack[ms->top];
}

void minStackFree(MinStack *ms) {
    free(ms->stack);
    free(ms->min_stack);
    ms->stack = NULL;
    ms->min_stack = NULL;
    ms->top = -1;
    ms->capacity = 0;
}

void printMenu() {
    printf("\n=== Min Stack Menu ===\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Top\n");
    printf("4. Get Min\n");
    printf("5. Quit\n");
    printf("======================\n");
    printf("Enter your choice: ");
}

int main() {
    MinStack ms;
    minStackCreate(&ms, 4);
    int choice, x;
    int running = 1;

    while (running) {
        printMenu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                if (scanf("%d", &x) != 1) {
                    printf("Invalid number\n");
                    break;
                }
                minStackPush(&ms, x);
                printf("Pushed %d\n", x);
                break;

            case 2:
                if (!minStackPop(&ms)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Popped\n");
                }
                break;

            case 3: {
                int top = minStackTop(&ms);
                if (top != INT_MIN) {
                    printf("Top: %d\n", top);
                }
                break;
            }

            case 4: {
                int min = minStackGetMin(&ms);
                if (min != INT_MIN) {
                    printf("Min: %d\n", min);
                }
                break;
            }

            case 5:
                running = 0;
                break;

            default:
                printf("Invalid choice. Enter a number between 1 and 5.\n");
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    minStackFree(&ms);
    printf("Exiting program.\n");
    return 0;
}
