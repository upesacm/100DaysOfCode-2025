#include <stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{ 
        return 0;
    }
}

void push(struct stack* ptr,char val){
    if(isFull(ptr)){
        printf("stack overflow! cannot push %d to the stack\n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

char pop(struct stack *ptr){
    if (isEmpty(ptr)){
        printf("stack underflow! cannot pop.\n");
        return -1;
    }
    else{
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
} 

int paranthesisMatch(char * exp){
    //create and intialise a stack
    struct stack *sp;
    sp->size =100;
    sp->top=-1 ;
    sp->arr= (char *)malloc (sp->size * sizeof(char));
    
    for (int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i] == '{' || exp[i] == '['){
            push(sp,'i');
            }else if (exp[i]==')'  || exp[i] == '}' || exp[i] == ']'){
                if(isEmpty(sp)){
                    return 0;
                }
                pop(sp);
            }
        }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    char * exp ="([])";
    if(paranthesisMatch(exp)){
        printf("the parathesis is match");
    }
    else{
        printf("the paranthesis is not match");
    }
    return 0;
}
