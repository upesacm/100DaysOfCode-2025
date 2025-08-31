#include <stdio.h>
int minJumps(int arr[], int n) 
{
    if (n <= 1) 
        return 0;  
    if (arr[0] == 0) 
        return -1;  
    int jumps = 0;     
    int currEnd = 0;   
    int farthest = 0;   
    for (int i = 0; i < n - 1; i++) 
    {
        farthest = (farthest > i + arr[i]) ? farthest : (i + arr[i]);
        if (i == currEnd) 
        {
            jumps++;
            currEnd = farthest;
            if (currEnd >= n - 1)
                return jumps;
        }
    }
    return -1;
}
int main() 
{
    int arr[] = {2, 3, 1, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = minJumps(arr, n);
    if (result != -1)
        printf("Minimum jumps to reach end: %d\n", result);
    else
        printf("End is not reachable.\n");

    return 0;
}
