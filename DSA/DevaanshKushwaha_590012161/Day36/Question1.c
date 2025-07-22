#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StackNode {
    char data;
    struct StackNode* next;
};

struct StackNode* newNode(char data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode* root) {
    return !root;
}

void push(struct StackNode** root, char data) {
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

char pop(struct StackNode** root) {
    if (isEmpty(*root))
        return '\0';
    struct StackNode* temp = *root;
    *root = (*root)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    struct StackNode* root = NULL;
    int i;
    for (i = 0; i < strlen(str); i++) {
        push(&root, str[i]);
    }

    printf("Reversed string: ");
    while (!isEmpty(root)) {
        printf("%c", pop(&root));
    }
    printf("\n");

    return 0;
}
