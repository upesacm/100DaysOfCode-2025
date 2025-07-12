#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* appendNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return 1;
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct Node* secondHalf = reverseList(slow);
    struct Node* temp = secondHalf;
    struct Node* firstHalf = head;
    int isPalin = 1; 
    while (temp != NULL) {
        if (firstHalf->data != temp->data) {
            isPalin = 0;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }
    reverseList(secondHalf);
    return isPalin;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = appendNode(head, val);
    }
    printf("Linked List: ");
    printList(head);
    if (isPalindrome(head)) {
        printf("Output: true\n");
    } else {
        printf("Output: false\n");
    }
    return 0;
}
