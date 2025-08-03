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

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf("->");
        temp = temp->next;
    }
    printf("\n");
}

int swapK(struct Node** headRef, int k, int n) {
    if (k > n) return 1;  
    if (2 * k - 1 == n) return 1;  
    struct Node* x = *headRef;
    struct Node* x_prev = NULL;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }

    struct Node* y = *headRef;
    struct Node* y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }

    if (x_prev) x_prev->next = y;
    else *headRef = y;

    if (y_prev) y_prev->next = x;
    else *headRef = x;

    struct Node* temp = x->next;
    x->next = y->next;
    y->next = temp;

    return 1;
}

int main() {
    int n, k, val;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Enter k: ");
    scanf("%d", &k);

    int result = swapK(&head, k, n);

    if (result)
        printf("true\n");
    else
        printf("false\n");

    printf("Modified Linked List: ");
    printList(head);

    return 0;
}
