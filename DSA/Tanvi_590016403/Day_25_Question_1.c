#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a Node
struct Node {
    int data;
    struct Node* next;
};

// Helper to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function 1: Check if linked list is palindrome
bool isPalindromeUtil(struct Node** left, struct Node* right) {
    if (right == NULL)
        return true;

    bool isPal = isPalindromeUtil(left, right->next);
    if (!isPal)
        return false;

    bool check = ((*left)->data == right->data);
    *left = (*left)->next;
    return check;
}

bool isPalindrome(struct Node* head) {
    return isPalindromeUtil(&head, head);
}

// Function 2: Find intersection of two sorted linked lists
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    struct Node* dummy = newNode(0);
    struct Node* tail = dummy;

    while (head1 && head2) {
        if (head1->data == head2->data) {
            tail->next = newNode(head1->data);
            tail = tail->next;
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->data < head2->data)
            head1 = head1->next;
        else
            head2 = head2->next;
    }
    return dummy->next;
}

// Function 3: Add two numbers represented by linked lists
struct Node* addLists(struct Node* l1, struct Node* l2) {
    struct Node* dummy = newNode(0);
    struct Node* curr = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        curr->next = newNode(sum % 10);
        curr = curr->next;
    }

    return dummy->next;
}

// Print the linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Sample linked lists for demonstration
int main() {
    // Palindrome Check
    struct Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(1);
    printf("Palindrome Check: ");
    printList(head1);
    printf("Is Palindrome? %s\n\n", isPalindrome(head1) ? "Yes" : "No");

    // Intersection
    struct Node* list1 = newNode(1);
    list1->next = newNode(2);
    list1->next->next = newNode(3);
    list1->next->next->next = newNode(4);
    list1->next->next->next->next = newNode(6);

    struct Node* list2 = newNode(2);
    list2->next = newNode(4);
    list2->next->next = newNode(6);
    list2->next->next->next = newNode(8);

    printf("List1: ");
    printList(list1);
    printf("List2: ");
    printList(list2);

    struct Node* inter = getIntersection(list1, list2);
    printf("Intersection: ");
    printList(inter);
    printf("\n");

    // Addition
    struct Node* num1 = newNode(4);
    num1->next = newNode(5);

    struct Node* num2 = newNode(3);
    num2->next = newNode(4);
    num2->next->next = newNode(5);

    printf("Number1: ");
    printList(num1);
    printf("Number2: ");
    printList(num2);

    struct Node* sum = addLists(num1, num2);
    printf("Sum: ");
    printList(sum);

    return 0;
}
