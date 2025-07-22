#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char st[MAX];
int top = -1;

void push(char c){ if(top<MAX-1) st[++top]=c; else exit(1); }
char pop(){ if(top>=0) return st[top--]; else exit(1); }

int is_pair(char o,char c){
    return (o=='('&&c==')') || (o=='['&&c==']') || (o=='{'&&c=='}');
}

int main(){
    char s[MAX];
    if(!fgets(s,MAX,stdin)) return 0;
    s[strcspn(s,"\n")]=0;
    for(int i=0; s[i]; i++){
        char ch = s[i];
        if(ch=='('||ch=='['||ch=='{') push(ch);
        else if(ch==')'||ch==']'||ch=='}'){
            char o = pop();
            if(!is_pair(o,ch)){
                printf("Not Balanced\n");
                return 0;
            }
        }
    }
    printf(top==-1 ? "Balanced\n" : "Not Balanced\n");
    return 0;
}
