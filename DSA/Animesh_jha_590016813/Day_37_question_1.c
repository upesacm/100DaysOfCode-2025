#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, int val) {
    if (isFull(ptr)) {
        printf("Stack overflow! Cannot push %d to the stack\n", val);
    } else {
        ptr->arr[++ptr->top] = val;
    }
}

int pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack underflow! Cannot pop.\n");
        return -1;
    } else {
        return ptr->arr[ptr->top--];
    }
}

int peek(struct stack *sp, int i) {
    int arrayInd = sp->top - i + 1;
    if (arrayInd < 0) {
        printf("Not a valid position for the stack\n");
        return -1;
    } else {
        return sp->arr[arrayInd];
    }
}

void sortStack(struct stack* input) {
 
    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    temp->size = input->size;
    temp->top = -1;
    temp->arr = (int*)malloc(temp->size * sizeof(int));

    while (!isEmpty(input)) {
        int tempVal = pop(input);

        while (!isEmpty(temp) && temp->arr[temp->top] > tempVal) {
            push(input, pop(temp));
        }

        push(temp, tempVal);
    }

    while (!isEmpty(temp)) {
        push(input, pop(temp));
    }

    free(temp->arr);
    free(temp);
}

int main() {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    printf("Stack has been created successfully.\n");

    push(sp, 3);
    push(sp, 1);
    push(sp, 4);
    push(sp, 2);
  
    printf("\nBefore sorting:\n");
    for (int j = 1; j <= sp->top + 1; j++) {
        printf("The value at index %d is %d\n", j, peek(sp, j));
    }

  
    sortStack(sp);

    printf("\nAfter sorting:\n");
    for (int j = 1; j <= sp->top + 1; j++) {
        printf("The value at index %d is %d\n", j, peek(sp, j));
    }

    free(sp->arr);
    free(sp);

    return 0;
}
