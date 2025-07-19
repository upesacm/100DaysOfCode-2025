#include<stdio.h>
//checking if two numbers have opposite signs
int haveOppositeSigns( int a,int b){
    return (a<0&&b>=0)||(a>=0&&b<0);

}
int main(){
    printf("Enter two integers..\n");
    int x, y;
    scanf("%d%d",&x,&y);
    if(haveOppositeSigns(x,y))printf("They have opposite signs.\n");
    else printf("They don't have opposite signs");
    return 0;
}