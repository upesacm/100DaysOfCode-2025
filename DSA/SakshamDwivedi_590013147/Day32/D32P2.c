#include <stdio.h>

int size;
int arr[100];
int current_xor = 0;

int main(){
  printf("Enter number of elements : ");
  scanf("%d", &size);
  printf("Enter the array : ");
  for(int i = 0; i < size; i++){
    scanf("%d", &arr[i]);
  }
  for(int i = 0; i < size; i++){
    current_xor = current_xor ^ arr[i];
  }
  printf("Non Repeating : %d", current_xor);

  return 0;
}
