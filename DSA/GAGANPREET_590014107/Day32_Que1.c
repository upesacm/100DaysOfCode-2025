#include<stdio.h>
int main(){
    int a = 4, b = 7;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("a = %d, b = %d\n", a, b);
    a = 1; 
    b = 2;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
