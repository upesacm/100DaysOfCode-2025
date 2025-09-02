#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    int freq[256]={0};
    printf("Enter the string: ");
    scanf("%s",str);
    for(int i=0;str[i]!='\0';i++){
        freq[(int)str[i]]++;
    }
    int oddsum=0;
    for(int i=0;i<256;i++){
        if(freq[i]%2!=0){
            oddsum++;
        }
    }
    if(oddsum<=1){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}
