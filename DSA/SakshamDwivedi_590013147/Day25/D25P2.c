#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* head2 = NULL;
void createNode(struct node**, int);
void Print(struct node**);
struct node* Intersection(struct node**, struct node**);

int main(){
    createNode(&head, 1);
    createNode(&head, 2);
    createNode(&head, 3);
    createNode(&head, 4);
    createNode(&head, 5);
    createNode(&head2, 2);
    createNode(&head2, 4);
    createNode(&head2, 6);
    createNode(&head2, 7);
    createNode(&head2, 8);
    Print(&head);
    Print(&head2);
    struct node* result = Intersection(&head, &head2);
    Print(&result);
}

void createNode(struct node** ll, int data){
       struct node* Node = (struct node*)malloc(sizeof(struct node));
       Node -> data = data;
       Node -> next = NULL;
       if(*ll == NULL){
            *ll = Node;
            return;
       }
     struct node* current = *ll;
     while(current -> next != NULL){
      current = current -> next;
     }
     current -> next = Node;
}

void Print(struct node** ll){
    struct node* current = *ll;
    while(current != NULL){
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");

}

struct node* Intersection(struct node** ll, struct node** ll2){

    struct node* new_list = NULL;
    struct node* l1 = *ll;

    while(l1 != NULL){
        struct node* l2 = *ll2;
        while(l2 != NULL){
            if(l1 -> data == l2 ->data){
                createNode(&new_list, l1 -> data);
                break;
            }
            l2 = l2 -> next;
        }
        l1 = l1 -> next;
    }

    return new_list;

}
