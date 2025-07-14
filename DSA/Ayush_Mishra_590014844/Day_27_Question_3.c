#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

struct Node* removeKthNode(struct Node* head, int k) {
    if (k <= 0) return head;
    struct Node* temp = head;
    struct Node* prev = NULL;
    int count = 1;
    while (temp) {
        if (count % k == 0) {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
        count++;
    }
    return head;
}

int main() {
    int n, k;
    scanf("%d", &n);
    struct Node* head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (!head) head = newNode;
        else tail->next = newNode;
        tail = newNode;
    }
    scanf("%d", &k);
    head = removeKthNode(head, k);
    printList(head);
    return 0;
}
