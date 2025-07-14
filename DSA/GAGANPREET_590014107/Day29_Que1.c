#include<stdio.h>
const char* check_even_odd(int n){
    return(n & 1)?"Odd":"Even";
}
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("%d is %s\n", num, check_even_odd(num));
    return 0;
}
