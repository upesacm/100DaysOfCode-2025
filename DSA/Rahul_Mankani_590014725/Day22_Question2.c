#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int val;
    struct Node* nxt;
};
struct Node* newNode(int val) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->nxt = NULL;
    return node;
}
int countKey(struct Node* head, int key) 
{
    struct Node* curr = head;
    int cnt = 0;
    while (curr != NULL) 
    {
        if (curr->val == key) 
        {
            cnt++;
        }
        curr = curr->nxt;
    }
    return cnt;
}
void printList(struct Node* head) 
{
    struct Node* tmp = head;
    while (tmp != NULL) 
    {
        printf("%d -> ", tmp->val);
        tmp = tmp->nxt;
    }
    printf("NULL\n");
}
int main() 
{
    struct Node* head = newNode(1);
    head->nxt = newNode(2);
    head->nxt->nxt = newNode(1);
    head->nxt->nxt->nxt = newNode(3);
    head->nxt->nxt->nxt->nxt = newNode(1);
    printf("Linked List: ");
    printList(head);
    int key = 1;
    int cnt = countKey(head, key);
    printf("Count of %d: %d\n", key, cnt);
    key = 2;
    cnt = countKey(head, key);
    printf("Count of %d: %d\n", key, cnt);
    struct Node* curr = head;
    struct Node* nxt;
    while (curr != NULL) 
    {
        nxt = curr->nxt;
        free(curr);
        curr = nxt;
    }
    return 0;
}
