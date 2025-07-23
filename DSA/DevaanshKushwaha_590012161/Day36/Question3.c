#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode* root) {
    return !root;
}

void push(struct StackNode** root, int data) {
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

int pop(struct StackNode** root) {
    if (isEmpty(*root))
        return -1;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

void printStack(struct StackNode* root) {
    if (isEmpty(root)) {
        return;
    }
    printf("%d ", root->data);
    printStack(root->next);
}

void insertAtBottom(struct StackNode** root, int data) {
    if (isEmpty(*root)) {
        push(root, data);
        return;
    }
    int temp = pop(root);
    insertAtBottom(root, data);
    push(root, temp);
}

int main() {
    struct StackNode* root = NULL;

    push(&root, 3);
    push(&root, 2);
    push(&root, 1);

    printf("Original Stack: ");
    printStack(root);
    printf("\n");

    int x = 0;
    insertAtBottom(&root, x);

    printf("Stack after inserting %d at bottom: ", x);
    printStack(root);
    printf("\n");

    struct StackNode* root2 = NULL;
    push(&root2, 6);
    push(&root2, 5);

    printf("Original Stack: ");
    printStack(root2);
    printf("\n");

    x = 9;
    insertAtBottom(&root2, x);

    printf("Stack after inserting %d at bottom: ", x);
    printStack(root2);
    printf("\n");

    return 0;
}
