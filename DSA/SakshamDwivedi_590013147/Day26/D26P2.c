#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int size1 = 0;
int size2 = 0;
struct node* head1 = NULL;
struct node* head2 = NULL;
struct node* unionHead = NULL;

void createNode1(int);
void createNode2(int);
void Print(struct node*);
void makeUnion();
void insertSortedUnique(int);

int main(){
    createNode1(9);
    createNode1(6);
    createNode1(4);
    createNode1(2);
    createNode1(3);
    createNode1(8);

    createNode2(1);
    createNode2(2);
    createNode2(8);
    createNode2(6);
    createNode2(2);

    printf("List 1 : ");
    Print(head1);
    printf("List 2 : ");
    Print(head2);
    printf("Union List : ");
    makeUnion();
    Print(unionHead);
}

void createNode1(int data){
    struct node* Node;
    struct node* current;

    Node = (struct node*)malloc(sizeof(struct node));
    Node -> data = data;
    Node -> next = NULL;

    if(head1 == NULL){
        head1 = Node;
        size1++;
        return;
    }

    current = head1;
    while(current -> next != NULL){
        current = current -> next;
    }

    current -> next = Node;
    size1++;
}

void createNode2(int data){
    struct node* Node;
    struct node* current;

    Node = (struct node*)malloc(sizeof(struct node));
    Node -> data = data;
    Node -> next = NULL;

    if(head2 == NULL){
        head2 = Node;
        size2++;
        return;
    }

    current = head2;
    while(current -> next != NULL){
        current = current -> next;
    }

    current -> next = Node;
    size2++;
}

void Print(struct node* head){
    struct node* current;

    current = head;
    while(current != NULL){
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}

void makeUnion(){
    struct node* current;

    current = head1;
    while(current != NULL){
        insertSortedUnique(current -> data);
        current = current -> next;
    }

    current = head2;
    while(current != NULL){
        insertSortedUnique(current -> data);
        current = current -> next;
    }
}

void insertSortedUnique(int val){
    struct node* newNode;
    struct node* current;
    struct node* prev;

    current = unionHead;
    prev = NULL;

    while(current != NULL && current -> data < val){
        prev = current;
        current = current -> next;
    }

    if(current != NULL && current -> data == val){
        return;
    }

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = val;
    newNode -> next = current;

    if(prev == NULL){
        unionHead = newNode;
    } else {
        prev -> next = newNode;
    }
}
