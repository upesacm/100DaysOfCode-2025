#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int top = -1;
int st[MAX];

void push(int x){
    if(top < MAX - 1) st[++top] = x;
    else exit(1);
}

int pop(){
    if(top >= 0) return st[top--];
    else exit(1);
}

void insertAtBottom(int x){
    if(top == -1){
        push(x);
    } else {
        int a = pop();
        insertAtBottom(x);
        push(a);
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    int x = 0;
    insertAtBottom(x);
    while(top >= 0) printf("%d ", pop());
    return 0;
}
