#include <stdio.h>
#include <stdlib.h>

typedef struct TwoStacks {
    int* arr;
    int capacity;
    int top1;
    int top2;
} TwoStacks;

TwoStacks* createTwoStacks(int capacity) {
    TwoStacks* ts = (TwoStacks*)malloc(sizeof(TwoStacks));
    ts->capacity = capacity;
    ts->arr = (int*)malloc(capacity * sizeof(int));
    ts->top1 = -1;
    ts->top2 = capacity;
    return ts;
}

void push1(TwoStacks* ts, int value) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[++ts->top1] = value;
        printf("Pushed %d to Stack1\n", value);
    } else {
        printf("Stack Overflow\n");
    }
}

void push2(TwoStacks* ts, int value) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[--ts->top2] = value;
        printf("Pushed %d to Stack2\n", value);
    } else {
        printf("Stack Overflow\n");
    }
}

int pop1(TwoStacks* ts) {
    if (ts->top1 >= 0) {
        int value = ts->arr[ts->top1--];
        return value;
    } else {
        printf("Stack1 Underflow\n");
        return -1;
    }
}

int pop2(TwoStacks* ts) {
    if (ts->top2 < ts->capacity) {
        int value = ts->arr[ts->top2++];
        return value;
    } else {
        printf("Stack2 Underflow\n");
        return -1;
    }
}

void printStacks(TwoStacks* ts) {
    printf("Stack1: ");
    for (int i = 0; i <= ts->top1; i++) {
        printf("%d ", ts->arr[i]);
    }
    printf("\n");

    printf("Stack2: ");
    for (int i = ts->capacity - 1; i >= ts->top2; i--) {
        printf("%d ", ts->arr[i]);
    }
    printf("\n");
}

void freeTwoStacks(TwoStacks* ts) {
    free(ts->arr);
    free(ts);
}

int main() {
    int capacity, choice, value;
    printf("Enter the total capacity of the array: ");
    scanf("%d", &capacity);
    TwoStacks* ts = createTwoStacks(capacity);

    while (1) {
        printf("\n---Menu---\n");
        printf("1. Push to Stack1\n");
        printf("2. Push to Stack2\n");
        printf("3. Pop from Stack1\n");
        printf("4. Pop from Stack2\n");
        printf("5. Print Stacks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push1(ts, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push2(ts, value);
                break;
            case 3:
                value = pop1(ts);
                if(value != -1) printf("Popped %d from Stack1\n", value);
                break;
            case 4:
                value = pop2(ts);
                if(value != -1) printf("Popped %d from Stack2\n", value);
                break;
            case 5:
                printStacks(ts);
                break;
            case 6:
                freeTwoStacks(ts);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
