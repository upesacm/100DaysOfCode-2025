#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node * createNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node ));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void printLinkedList(int n,struct node *head)
    {
        struct node *temp=head;
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");    
}
//SOrting linked list of 0s, 1s, 2s:
void sortLinkedList(struct node *head){
    if(head==NULL) return;
    int count[3] = {0, 0, 0};
    struct node *temp = head;
    while (temp != NULL) {
        count[temp->data]++;
        temp = temp->next;
    }
    temp = head;
    for (int i = 0; i < 3; i++) {
        while (count[i] > 0) {
            temp->data = i;
            temp = temp->next;
            count[i]--;
        }

    }



     
}
int main(){
    struct node *head=createNode(2);
    head->next=createNode(0);
    head->next->next=createNode(1);
    head->next->next->next=createNode(2);
    head->next->next->next->next=createNode(0);
    printf("Linked list before sorting:\n");
    printLinkedList(5,head);
    sortLinkedList(head);
    printf("Linked list after sorting:\n");
    printLinkedList(5,head);
    return 0;
}