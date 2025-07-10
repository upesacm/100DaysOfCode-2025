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

int main(){
    createNode(1);
    createNode(2);
    createNode(3);
    createNode(4);
    createNode(5);
    //createNode(6);
    Print();
    int mid = size / 2;
    printf("\n");
    struct node* trav = head;
    for(int i = 0; i < mid; i++){
       trav = trav -> next;
    }
    if(size % 2 == 0){
       printf("Mid point : %d", trav -> data);
    }
    else{
       printf("Mid points : %d", trav -> data);
       printf(", %d", trav -> next -> data);
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
     Node -> next = NULL;
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
