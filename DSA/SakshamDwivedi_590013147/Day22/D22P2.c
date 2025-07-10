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
int frequency(int);

int main() {
    createNode(1);
    createNode(2);
    createNode(3);
    createNode(2);
    createNode(4);
    createNode(2);
    Print();
    
    int key = 2;
    int freq = frequency(key);
    printf("\nFrequency of %d : %d", key, freq);
    
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

int frequency(int key) {
    int count = 0;
    struct node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    return count;
}
