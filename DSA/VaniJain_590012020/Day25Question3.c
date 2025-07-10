#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}
struct Node* reverse(struct Node* head) 
{
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
struct Node* addReversedLists(struct Node* l1, struct Node* l2) 
{
    struct Node* result = NULL;
    struct Node* tail = NULL;
    int carry = 0;
    while (l1 || l2 || carry) 
    {
        int sum = carry;
        if (l1) 
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) 
        {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        struct Node* newNode = createNode(sum % 10);
        if (!result) 
        {
            result = newNode;
            tail = newNode;
        } else 
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return result;
}
struct Node* removeLeadingZeros(struct Node* head) 
{
    while (head && head->data == 0 && head->next) 
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}
void inputList(struct Node** head, int n) 
{
    int val;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        insertEnd(head, val);
    }
}
void printList(struct Node* head) 
{
    while (head) 
    {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}
int main() 
{
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;
    struct Node* result = NULL;
    int n1, n2;
    printf("Enter number of digits in first number: ");
    scanf("%d", &n1);
    printf("Enter %d digits (in forward order):\n", n1);
    inputList(&num1, n1);
    printf("Enter number of digits in second number: ");
    scanf("%d", &n2);
    printf("Enter %d digits (in forward order):\n", n2);
    inputList(&num2, n2);
    num1 = reverse(num1);
    num2 = reverse(num2);
    result = addReversedLists(num1, num2);
    result = reverse(result);
    result = removeLeadingZeros(result);
    printf("Sum = ");
    printList(result);
    return 0;
}
