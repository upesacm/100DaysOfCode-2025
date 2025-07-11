#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) last = last->next;
    last->next = new_node;
}

int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

void makeUnion(struct Node* head1, struct Node* head2) {
    int arr[1000], size = 0;
    struct Node* temp;

    temp = head1;
    while (temp) {
        arr[size++] = temp->data;
        temp = temp->next;
    }

    temp = head2;
    while (temp) {
        arr[size++] = temp->data;
        temp = temp->next;
    }

    qsort(arr, size, sizeof(int), cmpfunc);

    struct Node* unionList = NULL;
    for (int i = 0; i < size; i++) {
        if (i == 0 || arr[i] != arr[i - 1])
            append(&unionList, arr[i]);
    }

    printf("Union list:\n");
    printList(unionList);
}

int main() {
    struct Node *L1 = NULL, *L2 = NULL;
    int n1, n2, val;
    printf("Enter number of nodes in List 1: ");
    scanf("%d", &n1);
    printf("Enter elements of List 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        append(&L1, val);
    }

    printf("Enter number of nodes in List 2: ");
    scanf("%d", &n2);
    printf("Enter elements of List 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        append(&L2, val);
    }

    makeUnion(L1, L2);
    return 0;
}
