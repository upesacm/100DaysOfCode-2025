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
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data < temp2->data) {
            temp1 = temp1->next;
        } else if (temp2->data < temp1->data) {
            temp2 = temp2->next;
        } else {
            result = appendNode(result, temp1->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return result;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n1, n2, val;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    printf("Enter number of elements in LinkedList1: ");
    scanf("%d", &n1);
    printf("Enter %d sorted elements:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        head1 = appendNode(head1, val);
    }

    printf("Enter number of elements in LinkedList2: ");
    scanf("%d", &n2);
    printf("Enter %d sorted elements:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        head2 = appendNode(head2, val);
    }

    printf("LinkedList1: ");
    printList(head1);
    printf("LinkedList2: ");
    printList(head2);

    struct Node* intersection = getIntersection(head1, head2);

    printf("Intersection: ");
    if (intersection == NULL)
        printf("No common elements\n");
    else
        printList(intersection);

    return 0;
}
