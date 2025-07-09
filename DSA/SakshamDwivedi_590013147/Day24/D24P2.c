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
void DeletePattern(int, int);

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
    DeletePattern(1, 2);
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
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");

}

void DeletePattern(int n, int m) {
    struct node *current = head;
    struct node *freenode = head;
    while(current != NULL){
        for(int i = 1; i < m; i++){
            if(current != NULL){
                current = current -> next;
            }
        }
        if(current == NULL || current -> next == NULL){
            break;
        }

        freenode = current -> next;
        for(int i = 0; i < n; i++){
            if(freenode!=NULL){
                struct node* del = freenode;
                freenode = freenode->next;
                free(del);
                size--;
            }
            current -> next = freenode;
            current = freenode;
        }
    }
}
