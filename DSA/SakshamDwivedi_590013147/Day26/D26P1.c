#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int size = 0;
int k;
struct node* head = NULL;
void createNode(int);
void Print();
void SwapKth(int);

int main(){
    createNode(1);
    createNode(2);
    createNode(3);
    createNode(4);
    createNode(5);
    printf("Enter k : ");
    scanf("%d", &k);
    printf("Before : ");
    Print();
    printf("\n");

    SwapKth(k);

    printf("After : ");
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

void SwapKth(int k){
    if(k > size || k < 1){
        printf("Invalid Value for K!\n");
        return;
    }

    if(2*k - 1 == size){
        return;
    }

    struct node *x = head;
    struct node *prevX = NULL;
    struct node *y = head;
    struct node *prevY = NULL;

    for(int i = 1; i < k; i++){
        prevX = x;
        x = x -> next;
    }

    for(int i = 1; i < size - k + 1; i++){
        prevY = y;
        y = y -> next;
    }

    if(prevX != NULL){
        prevX -> next = y;
    } else {
        head = y;
    }

    if(prevY != NULL){
        prevY -> next = x;
    } else {
        head = x;
    }

    struct node* temp = x -> next;
    x -> next = y -> next;
    y -> next = temp;
}
