#include <stdio.h>
#include <limits.h>
int main() 
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        fprintf(stderr, "Invalid number of days.\n");
        return 1;
    }
    int prices[n];
    for (int i = 0; i < n; i++) 
    {
        if (scanf("%d", &prices[i]) != 1) 
        {
            fprintf(stderr, "Invalid input.\n");
            return 1;
        }
    }
    int minPrice = INT_MAX;
    int maxProfit = 0;
    int buyDay = 0, sellDay = 0;
    for (int i = 0; i < n; i++) 
    {
        if (prices[i] < minPrice) 
        {
            minPrice = prices[i];
            buyDay = i;  
        }
        int profit = prices[i] - minPrice;
        if (profit > maxProfit) 
        {
            maxProfit = profit;
            sellDay = i;  
        }
    }
    printf("Maximum Profit: %d\n", maxProfit);
    if (maxProfit > 0)
        printf("Buy on Day %d at Price %d, Sell on Day %d at Price %d\n",
               buyDay + 1, prices[buyDay], sellDay + 1, prices[sellDay]);
    else
        printf("No profitable transaction possible.\n");
    return 0;
}
