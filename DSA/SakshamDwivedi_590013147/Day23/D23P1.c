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
int Traverse(int);
int pos;

int main(){
    createNode(1);
    createNode(2);
    createNode(3);
    createNode(4);
    createNode(5);
    printf("The Linked List : ")
    Print();
    printf("\n");
    printf("Enter the kth position : ");
    scanf("%d", &pos);
    if(pos < 1 || pos > size){
        printf("Invalid Position!");
    }
    else{
        printf("The element at %d position is %d", pos, Traverse(pos));
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
     size++; //The only reason I kept it here is for the invalid pos checking
}

void Print(){
    struct node* current = head;
    while(current != NULL){
        if(current -> next != NULL){
        printf("%d -> ", current -> data);}
        else{printf("%d", current -> data);}
        current = current -> next;
    }

}

int Traverse(int k) {
    struct node *fast = head;
    struct node *slow = head;
    for (int i = 0; i < k; i++) {
        if (fast == NULL)
            return -1;
        fast = fast->next;
    }
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}
