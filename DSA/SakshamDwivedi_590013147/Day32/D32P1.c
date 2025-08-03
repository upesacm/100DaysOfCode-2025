#include <stdio.h>

int num1;
int num2;

int main(){
  printf("Enter number 1 : ");
  scanf("%d", &num1);
  printf("Enter number 2 : ");
  scanf("%d", &num2);
  num1 = num1 ^ num2;
  num2 = num1 ^ num2;
  num1 = num1 ^ num2;
  printf("Number 1 : %d and Number 2 : %d\n", num1, num2);

  return 0;
}
