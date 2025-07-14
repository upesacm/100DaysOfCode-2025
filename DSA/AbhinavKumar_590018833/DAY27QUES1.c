#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
//to delete a node from a doubly LInked list:
void printLinkedList(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void deleteNode(struct node **head_ref, struct node *nodeToDelete) {
    if (nodeToDelete == NULL || *head_ref == NULL) return;
    if (*head_ref == nodeToDelete) *head_ref = nodeToDelete->next;
    if (nodeToDelete->next != NULL) nodeToDelete->next->prev = nodeToDelete->prev;
    if (nodeToDelete->prev != NULL) nodeToDelete->prev->next = nodeToDelete->next;
    free(nodeToDelete);
}
int main(){
    struct node *head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->prev = head->next;
    printf("Doubly Linked List before deletion:\n");
    printLinkedList(head);
    struct node *nodeToDelete = head->next; \
    deleteNode(&head, nodeToDelete);
    printf("Doubly Linked List after deletion:\n");
    printLinkedList(head);

}
