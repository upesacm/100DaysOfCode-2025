#include <stdio.h>
#define MAX 1000 
#define MAX_TYPES 1000 
int main() 
{
    int n;
    printf("Enter number of fruits: ");
    scanf("%d", &n);
    int fruits[MAX];
    printf("Enter the fruit types (as integers): ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &fruits[i]);
    }
    int count[MAX_TYPES] = {0}; 
    int left = 0, right = 0;
    int distinct = 0; 
    int maxLen = 0;
    while (right < n) 
    {
        if (count[fruits[right]] == 0) 
        {
            distinct++;
        }
        count[fruits[right]]++;
        right++;
        while (distinct > 2) 
        {
            count[fruits[left]]--;
            if (count[fruits[left]] == 0) 
            {
                distinct--;
            }
            left++;
        }
        if (right - left > maxLen) 
        {
            maxLen = right - left;
        }
    }
    printf("Length of longest subarray with at most two fruit types: %d\n", maxLen);
    return 0;
}
