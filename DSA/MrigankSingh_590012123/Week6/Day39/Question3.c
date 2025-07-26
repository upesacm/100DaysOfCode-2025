#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int top1;
    int top2;
    int capacity;
} TwoStacks;

void init_two_stacks(TwoStacks *ts, int initial_capacity) {
    ts->data = (int *)malloc(initial_capacity * sizeof(int));
    if (ts->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    ts->top1 = -1;
    ts->top2 = initial_capacity;
    ts->capacity = initial_capacity;
}

bool is_empty_stack1(TwoStacks *ts) {
    return ts->top1 < 0;
}

bool is_empty_stack2(TwoStacks *ts) {
    return ts->top2 >= ts->capacity;
}

bool is_full(TwoStacks *ts) {
    return ts->top1 + 1 == ts->top2;
}

void resize(TwoStacks *ts) {
    int new_capacity = ts->capacity * 2;
    int *new_data = (int *)malloc(new_capacity * sizeof(int));
    if (new_data == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }

    memcpy(new_data, ts->data, (ts->top1 + 1) * sizeof(int));

    int stack2_size = ts->capacity - ts->top2;
    int new_top2 = new_capacity - stack2_size;
    memcpy(new_data + new_top2, ts->data + ts->top2, stack2_size * sizeof(int));

    free(ts->data);
    ts->data = new_data;
    ts->top2 = new_top2;
    ts->capacity = new_capacity;
}

void push_stack1(TwoStacks *ts, int x) {
    if (is_full(ts)) {
        resize(ts);
    }
    ts->data[++(ts->top1)] = x;
}

void push_stack2(TwoStacks *ts, int x) {
    if (is_full(ts)) {
        resize(ts);
    }
    ts->data[--(ts->top2)] = x;
}

int pop_stack1(TwoStacks *ts) {
    if (is_empty_stack1(ts)) {
        fprintf(stderr, "Stack1 underflow\n");
        exit(EXIT_FAILURE);
    }
    return ts->data[(ts->top1)--];
}

int pop_stack2(TwoStacks *ts) {
    if (is_empty_stack2(ts)) {
        fprintf(stderr, "Stack2 underflow\n");
        exit(EXIT_FAILURE);
    }
    return ts->data[(ts->top2)++];
}

int top_stack1(TwoStacks *ts) {
    if (is_empty_stack1(ts)) {
        fprintf(stderr, "Stack1 is empty\n");
        exit(EXIT_FAILURE);
    }
    return ts->data[ts->top1];
}

int top_stack2(TwoStacks *ts) {
    if (is_empty_stack2(ts)) {
        fprintf(stderr, "Stack2 is empty\n");
        exit(EXIT_FAILURE);
    }
    return ts->data[ts->top2];
}

void free_two_stacks(TwoStacks *ts) {
    free(ts->data);
    ts->data = NULL;
    ts->top1 = -1;
    ts->top2 = 0;
    ts->capacity = 0;
}

void print_stacks(TwoStacks *ts) {
    printf("Stack1: [");
    for (int i = 0; i <= ts->top1; i++) {
        printf("%d", ts->data[i]);
        if (i < ts->top1) printf(", ");
    }
    printf("], Stack2: [");
    for (int i = ts->capacity - 1; i >= ts->top2; i--) {
        printf("%d", ts->data[i]);
        if (i > ts->top2) printf(", ");
    }
    printf("]\n");
}

void print_menu() {
    printf("\n=== Two Stacks Menu ===\n");
    printf("1. Push to Stack1\n");
    printf("2. Push to Stack2\n");
    printf("3. Pop from Stack1\n");
    printf("4. Pop from Stack2\n");
    printf("5. Top of Stack1\n");
    printf("6. Top of Stack2\n");
    printf("7. Quit\n");
    printf("=======================\n");
    printf("Enter your choice: ");
}

int main() {
    TwoStacks ts;
    init_two_stacks(&ts, 4);
    int choice, x;
    bool running = true;

    while (running) {
        print_menu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push to Stack1: ");
                if (scanf("%d", &x) != 1) {
                    printf("Invalid number\n");
                    break;
                }
                push_stack1(&ts, x);
                printf("Pushed %d to Stack1\n", x);
                break;

            case 2:
                printf("Enter value to push to Stack2: ");
                if (scanf("%d", &x) != 1) {
                    printf("Invalid number\n");
                    break;
                }
                push_stack2(&ts, x);
                printf("Pushed %d to Stack2\n", x);
                break;

            case 3:
                if (!is_empty_stack1(&ts)) {
                    printf("Popped %d from Stack1\n", pop_stack1(&ts));
                } else {
                    printf("Stack1 is empty\n");
                }
                break;

            case 4:
                if (!is_empty_stack2(&ts)) {
                    printf("Popped %d from Stack2\n", pop_stack2(&ts));
                } else {
                    printf("Stack2 is empty\n");
                }
                break;

            case 5:
                if (!is_empty_stack1(&ts)) {
                    printf("Top of Stack1: %d\n", top_stack1(&ts));
                } else {
                    printf("Stack1 is empty\n");
                }
                break;

            case 6:
                if (!is_empty_stack2(&ts)) {
                    printf("Top of Stack2: %d\n", top_stack2(&ts));
                } else {
                    printf("Stack2 is empty\n");
                }
                break;

            case 7:
                running = false;
                break;

            default:
                printf("Unknown choice. Please enter a number between 1 and 7.\n");
        }

        print_stacks(&ts);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    free_two_stacks(&ts);
    printf("Exiting program.\n");
    return 0;
}
