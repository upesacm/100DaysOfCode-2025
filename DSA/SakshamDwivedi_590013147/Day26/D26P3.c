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
void Sort_Whtvr_thtis();

int main(){
    createNode(1);
    createNode(2);
    createNode(2);
    createNode(1);
    createNode(2);
    createNode(0);
    createNode(2);
    createNode(2);

    printf("Before : ");
    Print();

    Sort_Whtvr_thtis();

    printf("After  : ");
    Print();
}

void createNode(int data){
    struct node* Node;
    struct node* current;

    Node = (struct node*)malloc(sizeof(struct node));
    Node -> data = data;
    Node -> next = NULL;

    if(head == NULL){
        head = Node;
        size++;
        return;
    }

    current = head;
    while(current -> next != NULL){
        current = current -> next;
    }

    current -> next = Node;
    size++;
}

void Print(){
    struct node* current;

    current = head;
    while(current != NULL){
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}

void Sort_Whtvr_thtis(){
    struct node* zeroHead = NULL;
    struct node* oneHead = NULL;
    struct node* twoHead = NULL;
    struct node* zeroTail = NULL;
    struct node* oneTail = NULL;
    struct node* twoTail = NULL;
    struct node* current = head;

    while(current != NULL){
        if(current -> data == 0){
            if(zeroHead == NULL){
                zeroHead = current;
                zeroTail = current;
            } else {
                zeroTail -> next = current;
                zeroTail = current;
            }
        } else if(current -> data == 1){
            if(oneHead == NULL){
                oneHead = current;
                oneTail = current;
            } else {
                oneTail -> next = current;
                oneTail = current;
            }
        } else {
            if(twoHead == NULL){
                twoHead = current;
                twoTail = current;
            } else {
                twoTail -> next = current;
                twoTail = current;
            }
        }
        current = current -> next;
    }

    if(zeroTail != NULL){
        zeroTail -> next = oneHead;
    }

    if(oneTail != NULL){
        oneTail -> next = twoHead;
    }

    if(twoTail != NULL){
        twoTail -> next = NULL;
    }

    if(zeroHead != NULL){
        head = zeroHead;
    } else if(oneHead != NULL){
        head = oneHead;
    } else {
        head = twoHead;
    }
}
