#include<stdio.h>
#include <stdlib.h>
#include <string.h>
//QUES IS TO SWAP THE Kth NOTE FROM THE END AND FROM THE START
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
void kthSwap(struct node *head, int k){
    if(head==NULL) return;
    int n=0;
    struct node *temp=head;
    while (temp!=NULL){
        n++;
        temp=temp->next;

    }
    if (k > n || k <= 0) {
        printf("INVALID K\n");
        return ;
    }
    if(2*k-1==n){
        return;
    }    
    struct node *kStart=head;
    for (int i=1;i<k;i++ ) kStart=kStart->next;
    struct node *kEnd=head;
    for (int i=1;i<n-k-1;i++) kEnd=kEnd->next;
    int tempData=kStart->data;
    kStart->data=kEnd->data;
    kEnd->data=tempData;

    

}
int main(){
    struct node *head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    printf("Linked l9ist before being swapped:\n");
    printLinkedList(4,head);
    int k=1;
    kthSwap(head,k);
    printf("Linked list after swapping %dth note from the start and the end :\n",k);
    printLinkedList(4,head);
    return 0;
}
