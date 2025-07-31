//Check if QUeue is Empty:
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
void isEmpty(){
    if(front==-1||front>rear){
        printf("Queue is Empty\n");
    }
    else{
        printf("Queue is not Empty\n");
    }    
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
    isEmpty();
    return 0;    
}

