#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* addLists(struct Node* l1, struct Node* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);
    struct Node* result = NULL;
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
        append(&result, sum % 10);
        carry = sum / 10;
    }
    result = reverse(result);
    while (result && result->data == 0 && result->next)
        result = result->next;
    return result;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node *num1 = NULL, *num2 = NULL;
    int n1, n2, val;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        append(&num1, val);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        append(&num2, val);
    }
    struct Node* sum = addLists(num1, num2);
    printList(sum);
    return 0;
}
