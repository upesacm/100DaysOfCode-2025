#include <stdio.h>
#include <stdlib.h>

struct SNode {
    int data;
    struct SNode* next;
};

struct SNode* createSNode(int data) {
    struct SNode* newNode = (struct SNode*)malloc(sizeof(struct SNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct SNode* insertEnd(struct SNode* head, int data) {
    struct SNode* newNode = createSNode(data);
    if (!head) return newNode;
    struct SNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

struct SNode* removeEveryKthNode(struct SNode* head, int k) {
    if (!head || k <= 0) return head;
    if (k == 1) {
        while (head) {
            struct SNode* temp = head;
            head = head->next;
            free(temp);
        }
        return NULL;
    }
    int count = 1;
    struct SNode* curr = head, *prev = NULL;
    while (curr) {
        if (count % k == 0) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
        count++;
    }
    return head;
}

void printList(struct SNode* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, val, k;
    struct SNode* head = NULL;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }
    printf("Enter value of k: ");
    scanf("%d", &k);
    head = removeEveryKthNode(head, k);
    printf("Updated List:\n");
    printList(head);
    return 0;
}
