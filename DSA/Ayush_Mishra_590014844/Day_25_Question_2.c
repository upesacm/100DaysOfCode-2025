#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!*head) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

Node* takeInput(int n) {
    Node* head = NULL;
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* intersectSorted(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* tail = NULL;
    while (list1 && list2) {
        if (list1->data == list2->data) {
            Node* newNode = createNode(list1->data);
            if (!result) {
                result = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
            list1 = list1->next;
            list2 = list2->next;
        } else if (list1->data < list2->data)
            list1 = list1->next;
        else
            list2 = list2->next;
    }
    return result;
}

int main() {
    int n1, n2;
    scanf("%d", &n1);
    Node* list1 = takeInput(n1);
    scanf("%d", &n2);
    Node* list2 = takeInput(n2);
    Node* intersection = intersectSorted(list1, list2);
    printList(intersection);
    return 0;
}
