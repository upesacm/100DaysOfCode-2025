#include<stdio.h>
#include<stdbool.h>
bool equal_subarray(int arr[],int n){
    if(n<2){
        return false;
    }
    int firstarr=0;
    for(int i=0;i<n;i++){
        firstarr+=arr[i];
        int secondarr=0;
        for(int j=i+1;j<n;j++){
            secondarr+=arr[j];
        }
        if(firstarr==secondarr){
            return true;
        }
    }
    return false;
}
int main(){
    int arr[]={5,5,11,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    
    if(equal_subarray(arr,n)){
        printf("true");
    }else{
        printf("false");
    }
    return 0;
}
