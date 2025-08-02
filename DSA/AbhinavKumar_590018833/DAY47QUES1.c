// . Insert Element at Rear of Queue
// A basic yet essential operation in queue handling that introduces the concept of enqueueing elements at the rear for standard FIFO behavior. This builds a strong foundation in linear data structure manipulation.

// Write a function that inserts a given element at the rear of a queue and returns the updated queue.

// This teaches rear insertion, queue dynamics, and is fundamental to real-time systems, task scheduling, and data buffering.

// Your task: Insert an element at the end of a queue and return the updated queue.

// Examples
// Input:

// Queue = [1, 2], Insert = 3
// Output:

// [1, 2, 3]
// Input:

// Queue = [4, 5], Insert = 6
// Output:

// [4, 5, 6]

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


typedef struct{
    int rear,front, size;
    unsigned capacity;
    int *array;
} Queue;
Queue* createQueue(unsigned capacity){
    Queue * queue= (Queue*)malloc(sizeof(Queue));
    queue->capacity=capacity;
    queue->front=queue->size=0;
    queue->rear=capacity-1;
    queue->array=(int *)malloc(sizeof(int));
    return queue;

}
bool isFull(Queue* queue){ return (queue->size==queue->capacity);}
void enqueue(Queue* queue, int item){ 
    if (!isFull(queue)){
        printf("Queue is Full");
        return;

    } 
    queue->rear=(queue->rear+1)%queue->capacity;
    queue->array[queue->rear]=item;
    queue->size=queue->size+1;
    printf("\nInserted %d into queue\n",item);
}
void printQueue(Queue* queue){
    if(queue->size==0){
        printf("[]");
        return;
    }
    printf("[");
    for(int i=0;i<queue->size;i++){
        int index=(queue->front+1)%queue->capacity;
        printf("%d",queue->array[index]);
        if(i<queue->size-1){
            printf(", ");

        }
    }
    printf("]");

}
int main() {
    printf("--- Example 1 ---\n");
    Queue* q1 = createQueue(10);
    enqueue(q1, 1);
    enqueue(q1, 2);
    
    printf("Initial Queue: ");
    printQueue(q1);
    printf("\nInserting element 3...\n");
    enqueue(q1, 3);
    
    printf("Final Queue: ");
    printQueue(q1);
    printf("\n\n");


    Queue* q2 = createQueue(10);
    enqueue(q2, 4);
    enqueue(q2, 5);

    printf("Initial Queue: ");
    printQueue(q2);
    printf("\nInserting element 6...\n");
    enqueue(q2, 6);

    printf("Final Queue: ");
    printQueue(q2);
    printf("\n");

    free(q1->array);
    free(q1);
    free(q2->array);
    free(q2);

    return 0;
}