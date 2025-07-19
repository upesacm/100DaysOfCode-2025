#include <stdio.h>

int num;

int main(){
    printf("Enter the number : ");
    scanf("%d", &num);
    num &= num - 1;
    printf("%d", num);

    return 0;
}
