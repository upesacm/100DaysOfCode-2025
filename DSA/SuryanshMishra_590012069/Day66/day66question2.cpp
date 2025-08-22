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
        int currentProfit = price - minPrice;        
        maxProfit = max(maxProfit, currentProfit);
    }    
    return maxProfit;
}
pair<int, pair<int, int>> maxProfitWithDays(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) return {0, {-1, -1}};    
    int minPrice = prices[0];
    int maxProfit = 0;
    int buyDay = 0;
    int sellDay = 0;
    int minPriceDay = 0;    
    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
            minPriceDay = i;
        }
        int currentProfit = prices[i] - minPrice;
        if (currentProfit > maxProfit) {
            maxProfit = currentProfit;
            buyDay = minPriceDay;
            sellDay = i;
        }
    }
    return {maxProfit, {buyDay, sellDay}};
}
int maxProfitSafe(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) return 0;    
    int minPrice = prices[0];
    int maxProfit = 0;    
    for (int i = 1; i < n; i++) {
        int currentProfit = prices[i] - minPrice;        
        maxProfit = max(maxProfit, currentProfit);        
        minPrice = min(minPrice, prices[i]);
    }    
    return maxProfit;
}
