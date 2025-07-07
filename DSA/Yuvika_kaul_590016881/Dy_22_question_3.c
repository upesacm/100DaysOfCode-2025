//question one
//Traverse and print all elements of a linked list in the correct order with proper
//spacing.

#include<stdio.h>

struct node{ //new data type created 
int data;//data of node
struct node*next;//address of next node 
};

int main(){
//creating 3 nodes 
  struct node*head = (struct node*)malloc(sizeof(struct node));//1st head node 
struct node*second = (struct node*)malloc(sizeof(struct node));//second node
struct node*third  = (struct node*)malloc(sizeof(struct node));// third node 

//assigning values to the node 
head ->data = 10;
head->next = second;

second->data = 20;
second->next = third;

third ->data = 30;
third ->next = NULL;

//traversing through the linklist 
struct node* current = head;
printf("the linklist is ");
while(current !=NULL){
printf("%d",current->data);
current = current ->next;
}

printf("NULL\n");

return 0;
}









