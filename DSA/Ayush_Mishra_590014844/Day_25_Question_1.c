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

Node* reverseList(Node* head) {
    Node *prev = NULL, *next = NULL;
    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

int isPalindrome(Node* head) {
    if (!head || !head->next) return 1;
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* secondHalf = reverseList(slow);
    Node* firstHalf = head;
    while (secondHalf) {
        if (firstHalf->data != secondHalf->data)
            return 0;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return 1;
}

int main() {
    int n, val;
    Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    if (isPalindrome(head))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
