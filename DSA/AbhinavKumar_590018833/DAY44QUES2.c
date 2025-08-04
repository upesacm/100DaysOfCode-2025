// 2. Find the Size of a Queue
// A problem that demonstrates queue metadata operations and teaches efficient size calculation techniques for dynamic data structures using built-in properties or iterative counting methods.

// Given a queue, write a program to return the number of elements present in it. This operation is fundamental in memory management and capacity planning where you need to monitor queue utilization and track data structure growth. The technique involves understanding size tracking mechanisms that can be implemented through direct property access or iterative counting depending on the queue implementation. This concept is essential in resource allocation, performance monitoring, and system optimization where knowing data structure sizes enables efficient memory management and capacity planning decisions.

// This introduces queue metadata analysis and size tracking techniques that are crucial for resource management and efficient queue capacity monitoring operations.

// Your task: Implement efficient queue size calculation using appropriate methods based on the underlying queue implementation and access patterns.

// Examples
// Input:

// Queue = [1, 2, 3, 4]
// Output:

// 4
// Input:

// Queue = [7]
// Output:

// 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int sizeOfQueue() {
    if (front == -1 || front > rear) {
        return 0;
    }
    return (rear - front + 1);
}

int main(){
     front=0;
    rear=3;
    queue[0]=10;
    queue[1]=20;
    queue[2]=30;
    queue[3]=40;
    displayQueue();
    printf("%d\n",sizeOfQueue());
    return 0;    
}

