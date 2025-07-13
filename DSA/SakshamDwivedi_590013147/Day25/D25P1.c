#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int size = 0;
struct node* head = NULL;
void createNode(int);
void Print();
struct node* Reverse(struct node*);
int isPalindrome(struct node*);

int main(){
    createNode(1);
    createNode(2);
    createNode(3);
    createNode(2);
    createNode(1);
    //createNode(6);
    Print();
    if(isPalindrome(head) == 1){
        printf("Palindrome!\n");
    }
    else{
        printf("Not Palindrome!\n");
    }
}

void createNode(int data){
       struct node* Node = (struct node*)malloc(sizeof(struct node));
       Node -> data = data;
       Node -> next = NULL;
       if(head == NULL){
            head = Node;
            size++;
            return;
       }
     struct node* current = head;
     while(current -> next != NULL){
      current = current -> next;
     }
     current -> next = Node;
     size++;
}

void Print(){
    struct node* current = head;
    while(current != NULL){
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");

}

struct node* reverse(struct node* head) {
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int isPalindrome(struct node* head) {
    if (head == NULL || head->next == NULL){
        return 1;
    }

    struct node* slow = head;
    struct node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = reverse(slow);
    slow = head;

    while (fast != NULL) {
        if (slow->data != fast->data){
            return 0;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return 1;
}
