#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct stack {
    int size;
    int top;
    float *arr;
};

int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

void push(struct stack *ptr, float val) {
    ptr->top++;
    ptr->arr[ptr->top] = val;
}

float pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack underflow! Cannot pop.\n");
        return -1;
    } else {
        float val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

float evaluatePostfix(char *postfix) {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (float *)malloc(sp->size * sizeof(float));

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(sp, postfix[i] - '0');  // Convert char to int
        } else {
            float operand2 = pop(sp);
            float operand1 = pop(sp);
            switch (postfix[i]) {
                case '+': push(sp, operand1 + operand2); break;
                case '-': push(sp, operand1 - operand2); break;
                case '*': push(sp, operand1 * operand2); break;
                case '/': push(sp, operand1 / operand2); break;
            }
        }
    }

    float result = pop(sp);
    free(sp->arr);
    free(sp);
    return result;
}

int main() {
    char postfix[] = "231*+9-";
    printf("Result of postfix evaluation: %.2f\n", evaluatePostfix(postfix));
    return 0;
}
