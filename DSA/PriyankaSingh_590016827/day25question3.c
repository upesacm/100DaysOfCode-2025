#include <stdio.h>
#include <stdlib.h>

// Linked list node definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append node to the end of the list
void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Add two linked lists
struct Node* addLists(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node** tail = &result;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        *tail = createNode(sum % 10);
        tail = &((*tail)->next);
    }

    // Remove leading zeros (optional for reverse order)
    // Not needed here because least significant digit comes first
    return result;
}

// Build a list from user input
void buildList(struct Node** headRef, int n) {
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(headRef, val);
    }
}

int main() {
    struct Node *num1 = NULL, *num2 = NULL, *sum = NULL;
    int n1, n2;

    printf("Enter number of digits in first number (least significant digit first): ");
    scanf("%d", &n1);
    printf("Enter digits of first number:\n");
    buildList(&num1, n1);

    printf("Enter number of digits in second number (least significant digit first): ");
    scanf("%d", &n2);
    printf("Enter digits of second number:\n");
    buildList(&num2, n2);

    printf("First Number: ");
    printList(num1);
    printf("Second Number: ");
    printList(num2);

    sum = addLists(num1, num2);

    printf("Sum: ");
    printList(sum);

    return 0;
}
