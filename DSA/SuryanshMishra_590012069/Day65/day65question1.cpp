#include <vector>
#include <algorithm>
#include <functional>
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
    sort(coins.begin(), coins.end(), greater<int>());    
    int coinCount = 0;
    vector<int> usedCoins;    
    for (int coin : coins) {
        if (amount == 0) break;       
        int numCoins = amount / coin;
        coinCount += numCoins;
        amount -= numCoins * coin;        
        for (int i = 0; i < numCoins; i++) {
            usedCoins.push_back(coin);
        }
    }    
    if (amount != 0) {
        return {-1, {}};
    }    
    return {coinCount, usedCoins};
}