#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) return 0;    
    int minPrice = INT_MAX;
    int maxProfit = 0;    
    for (int price : prices) {
        minPrice = min(minPrice, price);        
        // Calculate profit if selling at current price
        int currentProfit = price - minPrice;
        
        // Update maximum profit
        maxProfit = max(maxProfit, currentProfit);
    }
    
    return maxProfit;
}

// Alternative version that also returns buy and sell days
pair<int, pair<int, int>> maxProfitWithDays(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) return {0, {-1, -1}};
    
    int minPrice = prices[0];
    int maxProfit = 0;
    int buyDay = 0;
    int sellDay = 0;
    int minPriceDay = 0;
    
    for (int i = 1; i < n; i++) {
        // If we found a new minimum price, update it
        if (prices[i] < minPrice) {
            minPrice = prices[i];
            minPriceDay = i;
        }
        
        // Calculate profit if selling at current price
        int currentProfit = prices[i] - minPrice;
        
        // If current profit is better, update buy and sell days
        if (currentProfit > maxProfit) {
            maxProfit = currentProfit;
            buyDay = minPriceDay;
            sellDay = i;
        }
    }
    
    return {maxProfit, {buyDay, sellDay}};
}

// Version that handles the case where no profit is possible
int maxProfitSafe(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) return 0;
    
    int minPrice = prices[0];
    int maxProfit = 0;
    
    for (int i = 1; i < n; i++) {
        // Calculate profit if selling at current price
        int currentProfit = prices[i] - minPrice;
        
        // Update maximum profit (only if positive)
        maxProfit = max(maxProfit, currentProfit);
        
        // Update minimum price for future transactions
        minPrice = min(minPrice, prices[i]);
    }
    
    return maxProfit; // Returns 0 if no profit possible
}
