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

Node* addNumbers(Node* l1, Node* l2) {
    Node* result = NULL;
    Node* tail = NULL;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        Node* newNode = createNode(sum % 10);
        if (!result) {
            result = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return result;
}

int main() {
    int n1, n2;
    scanf("%d", &n1);
    Node* num1 = takeInput(n1);
    scanf("%d", &n2);
    Node* num2 = takeInput(n2);
    Node* sum = addNumbers(num1, num2);
    printList(sum);
    return 0;
}
