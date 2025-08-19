#include <vector>
#include <algorithm>
using namespace std;
int minCoins(vector<int>& coins, int amount) {
    if (amount == 0) return 0;    
    sort(coins.begin(), coins.end(), greater<int>());    
    int coinCount = 0;
    for (int coin : coins) {
        if (amount == 0) break;        
        int numCoins = amount / coin;
        coinCount += numCoins;
        amount -= numCoins * coin;
    }    
    return (amount == 0) ? coinCount : -1;
}
pair<int, vector<int>> minCoinsWithDetails(vector<int>& coins, int amount) {
    if (amount == 0) return {0, {}};
    
    // Sort coins in descending order for greedy approach
    sort(coins.begin(), coins.end(), greater<int>());
    
    int coinCount = 0;
    vector<int> usedCoins;
    
    for (int coin : coins) {
        if (amount == 0) break;
        
        // Use as many coins of this denomination as possible
        int numCoins = amount / coin;
        coinCount += numCoins;
        amount -= numCoins * coin;
        
        // Add used coins to result
        for (int i = 0; i < numCoins; i++) {
            usedCoins.push_back(coin);
        }
    }
    
    // If amount is not 0, it means we couldn't make exact change
    if (amount != 0) {
        return {-1, {}};
    }
    
    return {coinCount, usedCoins};
}