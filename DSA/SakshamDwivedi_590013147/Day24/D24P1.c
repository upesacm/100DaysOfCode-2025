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
void Reverse();

int main(){
    createNode(1);
    createNode(2);
    createNode(3);
    createNode(4);
    createNode(5);
    createNode(6);
    printf("Before : ");
    Print();
    printf("\n");
    printf("After : ");
    Reverse();
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

void Reverse() {
    struct node* current = head;
    struct node* ahead = head;
    struct node* before = NULL;
    while(current != NULL){
        ahead = ahead -> next;
        current -> next = before;
        before = current;
        current = ahead;
    }
    head = before;
}
