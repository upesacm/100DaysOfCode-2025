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
void RemoveDups();

int main(){
    createNode(1);
    createNode(2);
    createNode(2);
    createNode(2);
    createNode(3);
    createNode(4);
    createNode(4);
    createNode(4);
    createNode(4);
    createNode(4);
    createNode(5);
    Print();
    printf("\n");
    RemoveDups();
    Print();
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
        if(current -> next != NULL){
        printf("%d -> ", current -> data);}
        else{printf("%d", current -> data);}
        current = current -> next;
    }

}

void RemoveDups() {
    struct node *trav1 = head;
    struct node *trav2 = head;
    struct node *travfree = NULL;
    trav2 = trav2 -> next;
    while(trav2 != NULL){
        if(trav1 -> data == trav2 -> data){
            trav1 -> next = trav2 -> next;
            travfree = trav2;
            trav2 = trav2 -> next;
            free(travfree);
            size--;
        }
        else{
            trav2 = trav2 -> next;
            trav1 = trav1 -> next;
        }
    }

}
