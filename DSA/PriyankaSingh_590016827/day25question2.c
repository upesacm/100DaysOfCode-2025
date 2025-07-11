#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append node to end of list
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
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Find intersection of two sorted linked lists
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node** tail = &result;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data) {
            *tail = createNode(head1->data);
            tail = &((*tail)->next);
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->data < head2->data) {
            head1 = head1->next;
        } else {
            head2 = head2->next;
        }
    }

    return result;
}

// Build linked list
void buildList(struct Node** headRef, int n) {
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(headRef, val);
    }
}

// Main function
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* intersect = NULL;
    int n1, n2;

    printf("Enter number of elements in first sorted list: ");
    scanf("%d", &n1);
    printf("Enter elements of first list (sorted):\n");
    buildList(&list1, n1);

    printf("Enter number of elements in second sorted list: ");
    scanf("%d", &n2);
    printf("Enter elements of second list (sorted):\n");
    buildList(&list2, n2);

    printf("First List: ");
    printList(list1);

    printf("Second List: ");
    printList(list2);

    intersect = getIntersection(list1, list2);

    printf("Intersection List: ");
    printList(intersect);

    return 0;
}
