#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int size = 0;
struct node* head = NULL;

void createNode(int);
void Print();

int main() {
    createNode(10);
    createNode(20);
    createNode(30);
    createNode(40);
    createNode(50);
    Print();
    return 0;
}

void createNode(int data) {
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node->data = data;
    Node->next = NULL;
    if (head == NULL) {
        head = Node;
        size++;
        return;
    }
    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = Node;
    size++;
}

void Print() {
    struct node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
}
