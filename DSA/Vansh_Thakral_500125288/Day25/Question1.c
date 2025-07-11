#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* reverse(struct Node* head) {
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


bool isPalindrome(struct Node* head) {
    if (!head || !head->next) return true;


    struct Node* slow = head;
    struct Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }


    struct Node* secondHalf = reverse(slow->next);
    struct Node* temp1 = head;
    struct Node* temp2 = secondHalf;

 
    bool result = true;
    while (temp2) {
        if (temp1->data != temp2->data) {
            result = false;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }


    slow->next = reverse(secondHalf);

    return result;
}


struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
