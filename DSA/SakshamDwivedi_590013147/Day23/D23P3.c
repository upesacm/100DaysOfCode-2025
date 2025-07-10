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
void RemoveMid();

int main(){
    createNode(1);
    createNode(2);
    createNode(3);
    createNode(4);
    createNode(5);
    //createNode(6);
    printf("Before : ");
    Print();
    printf("\n");
    printf("After : ");
    RemoveMid();
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

void RemoveMid() {
    int mid = size / 2;
    int count = 1;
    struct node *trav = head;
    struct node *freetrav = NULL;
    while(count != mid){
        trav = trav -> next;
        count++;
    }

    freetrav = trav -> next;
    trav -> next = trav -> next -> next;
    free(freetrav);
    size--;
}
