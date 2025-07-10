#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int size = 0;
int m;
struct node* head = NULL;
void createNode(int);
void Print();
void Delete(int);

int main(){
    createNode(1);
    createNode(2);
    createNode(3);
    createNode(4);
    createNode(5);
    createNode(6);
    printf("Enter the position : ");
    scanf("%d", &m);
    printf("Before : ");
    Print();
    printf("\n");
    printf("After : ");
    Delete(m);
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

void Delete(int pos) {
    if(pos < 0 || pos > size){
        return;
    }
    struct node *current = head;
    struct node *freenode = head;
    if(pos == 1){
        head = current -> next;
        freenode = current;
        free(freenode);
        return;
    }
    for(int i = 1; i < pos - 1; i++){
        current = current -> next;
    }
    freenode = current -> next;
    current -> next = freenode -> next;
    free(freenode);
    size--;
}
