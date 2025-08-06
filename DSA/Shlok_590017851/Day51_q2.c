#include <stdio.h>
#include <limits.h>

int smallestSubarrayWithSumGreaterThanX(int arr[], int n,int x) 
{
    int min_len=INT_MAX;
    int start=0,end=0;
    int curr_sum=0;

    while (end<n) 
    {
        while (curr_sum<=x && end<n) 
        {
            curr_sum+=arr[end++];
        }
        while (curr_sum>x && start<n)
          {
            if (end-start<min_len)
            {
                min_len=end-start;
            }
            curr_sum-=arr[start++];
        }
    }
    return (min_len==INT_MAX)?0:min_len;
}
int main() 
{
    int arr1[]={1,4,45,6,0,19};
    int x1=51;
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    printf("Output: %d\n",smallestSubarrayWithSumGreaterThanX(arr1,n1,x1)); 

    int arr2[]={1,10,5,2,7};
    int x2=9;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Output: %d\n", smallestSubarrayWithSumGreaterThanX(arr2, n2, x2)); 
    return 0;
}
