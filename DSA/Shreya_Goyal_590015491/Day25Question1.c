#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* naya = (struct Node*)malloc(sizeof(struct Node));
    naya->data = value;
    naya->next = NULL;
    return naya;
}

struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

int isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return 1;

    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* secondHalf = reverseList(slow);
    struct Node* firstHalf = head;

    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data)
            return 0;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return 1;
}

int main() {
    int n, i, val;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Now add %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* nayaNode = createNode(val);
        if (head == NULL) {
            head = tail = nayaNode;
        } else {
            tail->next = nayaNode;
            tail = nayaNode;
        }
    }

    if (isPalindrome(head))
        printf("Palindrome\n");
    else
        printf("Not palidrome\n");

    return 0;
}
