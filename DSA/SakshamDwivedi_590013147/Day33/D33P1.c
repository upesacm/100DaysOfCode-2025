#include <stdio.h>

int num1, num2;

int main()
{
    printf("Enter number 1 : ");
    scanf("%d", &num1);
    printf("Enter number 2 : ");
    scanf("%d", &num2);
    num1 = (num1 >> 31) & 1;
    num2 = (num2 >> 31) & 1;
    if(num1 ^ num2 == 1){
        printf("True\n");
    }
    else{
        printf("False\n");
    }

    return 0;
}
