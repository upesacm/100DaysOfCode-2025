#include <stdio.h>
#include <stdlib.h>
struct ListNode 
{
    int val;
    struct ListNode* next;
};
struct ListNode* createNode(int val)
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode* prev = NULL;
    while (head) 
    {
        struct ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
struct ListNode* addReversed(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* dummy = createNode(0);
    struct ListNode* curr = dummy;
    int carry = 0;

    while (l1 || l2 || carry) 
    {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }

        carry = sum / 10;
        curr->next = createNode(sum % 10);
        curr = curr->next;
    }
    return dummy->next;
}
struct ListNode* removeLeadingZeros(struct ListNode* head)
{
    while (head && head->val == 0 && head->next) 
    {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}
struct ListNode* addNumbers(struct ListNode* num1, struct ListNode* num2) 
{
    struct ListNode* rev1 = reverse(num1);
    struct ListNode* rev2 = reverse(num2);
    struct ListNode* sumReversed = addReversed(rev1, rev2);
    struct ListNode* result = reverse(sumReversed);
    return removeLeadingZeros(result);
}
void printList(struct ListNode* head) 
{
    while (head)
      {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}
int main() 
{
    struct ListNode* num1 = createNode(1);
    num1->next = createNode(9);
    num1->next->next = createNode(0);

    struct ListNode* num2 = createNode(2);
    num2->next = createNode(5);

    struct ListNode* result = addNumbers(num1, num2);
    printf("Sum: ");
    printList(result); 
    return 0;
}
