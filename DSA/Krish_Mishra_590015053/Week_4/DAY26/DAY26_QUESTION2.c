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

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (!*head) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    int arr[1000], i = 0;
    struct Node *temp1 = head1, *temp2 = head2;

    while (temp1) {
        arr[i++] = temp1->data;
        temp1 = temp1->next;
    }
    while (temp2) {
        arr[i++] = temp2->data;
        temp2 = temp2->next;
    }

    qsort(arr, i, sizeof(int), cmpfunc);

    struct Node* unionHead = NULL;
    for (int j = 0; j < i; j++) {
        // Only insert if it's the first element or different from previous
        if (j == 0 || arr[j] != arr[j - 1]) {
            insertEnd(&unionHead, arr[j]);
        }
    }
    return unionHead;
}

int main() {
    int n1, n2, val;
    struct Node *head1 = NULL, *head2 = NULL;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n1);
    printf("Enter %d elements:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        insertEnd(&head1, val);
    }

    printf("Enter number of elements in second list: ");
    scanf("%d", &n2);
    printf("Enter %d elements:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        insertEnd(&head2, val);
    }

    struct Node* unionList = makeUnion(head1, head2);
    printf("Union of both lists:\n");
    printList(unionList);

    return 0;
}
