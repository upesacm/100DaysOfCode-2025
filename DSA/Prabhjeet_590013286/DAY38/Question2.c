#include <stdio.h>
#define MAX 10000

int data[MAX], minData[MAX], top = -1;

void func(int val) {
    data[++top] = val;
    if(top == 0) minData[top] = val;
    else minData[top] = val < minData[top-1] ? val : minData[top-1];
}

void pop() {
    if(top >= 0) top--;
}

int getMin() {
    if(top >= 0) return minData[top];
    return -1;
}

int main() {
    int n, x, op;
    scanf("%d", &n); 
    for(int i=0;i<n;i++) {
        scanf("%d", &op);
        if(op==1) {
            scanf("%d", &x);
            func(x);
        }
        else if(op==2) pop();
        else if(op==3) printf("%d\n", getMin());
    }
    return 0;
}
