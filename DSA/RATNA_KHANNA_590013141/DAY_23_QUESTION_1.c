#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* createnode(int newdata) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = newdata;
    newnode->next = NULL;
    return newnode;
}
struct node* createlist(int n) {
    struct node *head = NULL, *temp = NULL, *current = NULL;
    int data;
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        temp = createnode(data);
        if (head == NULL) {
            head = temp;
        } else {
            current->next = temp;
        }
        current = temp;
    }
    return head;
}
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void kthfromend(struct node* head, int k) 
{
    struct node* fast = head;
    struct node* slow = head;
    for (int i = 0; i < k; i++) 
    {
        if (fast == NULL) 
        {
            printf("-1\n");
            return;
        }
        fast = fast->next;
    }
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    if (slow != NULL)
        printf("%d\n", slow->data);
    else
        printf("-1\n");
}
int main() {
    int n, k;
    struct node* head = NULL;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    head = createlist(n);
    printf("The linked list elements are: ");
    display(head);
    printf("Enter the value of k: ");
    scanf("%d", &k);
    kthfromend(head, k);
    return 0;
}
