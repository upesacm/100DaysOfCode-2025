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

int findKthFromEnd(struct Node* head, int k) 
{
    struct Node* first = head;
    struct Node* second = head;

    for (int i = 0; i < k; i++) {
        if (first == NULL)
            return -1;  
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

            if (second != NULL)
            return second->data;
        else
            return -1;

}

int main() {
    struct Node* head = NULL;
    int n, value, k;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d node values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = appendNode(head, value);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    int result = findKthFromEnd(head, k);
    printf("Kth node from end: %d\n", result);

    return 0;
}
