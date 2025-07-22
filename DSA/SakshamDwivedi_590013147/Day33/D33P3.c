#include <stdio.h>

int num;

int main(){
    printf("Enter the number : ");
    scanf("%d", &num);
    num &= -num;
    printf("%d", num);

    return 0;
}
