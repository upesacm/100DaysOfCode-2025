#include <stdio.h>
#include <limits.h>

#define MAX 100

int stack[MAX], maxStack[MAX];
int top1 = -1, top2 = -1;

void push(int x) {
    stack[++top1] = x;
    if (top2 == -1 || x >= maxStack[top2])
        maxStack[++top2] = x;
    else
        maxStack[++top2] = maxStack[top2]; 
}

void pop() {
    if (top1 == -1) return;
    top1--;
    top2--;
}

int getMax() {
    if (top2 == -1) return INT_MIN;
    return maxStack[top2];
}

int top() {
    if (top1 == -1) return -1;
    return stack[top1];
}


int main() {
    push(3); push(5); push(2);
    printf("Max: %d\n", getMax()); 

    pop(); 
    printf("Max after pop: %d\n", getMax()); 

    pop(); 
    printf("Max after another pop: %d\n", getMax()); 

    return 0;
}

