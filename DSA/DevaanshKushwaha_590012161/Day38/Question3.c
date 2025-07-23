#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a stack node
typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

// Structure to represent a stack
typedef struct {
    StackNode* top;
} Stack;

// Function to create a new stack node
StackNode* newStackNode(char data) {
    StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, char data) {
    StackNode* stackNode = newStackNode(data);
    stackNode->next = stack->top;
    stack->top = stackNode;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (isEmpty(stack))
        return '\0'; // Or handle error appropriately
    StackNode* temp = stack->top;
    char popped = temp->data;
    stack->top = temp->next;
    free(temp);
    return popped;
}

// Function to peek at the top element of the stack
char peek(Stack* stack) {
    if (isEmpty(stack))
        return '\0'; // Or handle error appropriately
    return stack->top->data;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to check for redundant brackets
char* findRedundantBrackets(char* expression) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (ch == '(' || isOperator(ch)) {
            push(stack, ch);
        } else if (ch == ')') {
            int hasOperator = 0;
            while (!isEmpty(stack) && peek(stack) != '(') {
                if (isOperator(peek(stack))) {
                    hasOperator = 1;
                }
                pop(stack);
            }
            // Pop the opening parenthesis
            if (!isEmpty(stack) && peek(stack) == '(') {
                pop(stack);
            }

            if (!hasOperator) {
                // Free stack memory before returning
                while(!isEmpty(stack)) {
                    pop(stack);
                }
                free(stack);
                return "Yes";
            }
        }
    }

    // Free stack memory if no redundant brackets found
    while(!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
    return "No";
}

int main() {
    char expression1[100];
    scanf("%s", expression1);
    printf("%s\n", findRedundantBrackets(expression1));

    char expression2[100];
    scanf("%s", expression2);
    printf("%s\n", findRedundantBrackets(expression2));

    return 0;
}
