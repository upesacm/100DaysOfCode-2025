#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend()); // sort descending
    int count = 0;
    for(int coin : coins) {
        while(amount >= coin) {
            amount -= coin;
            count++;
        }
    }
    return (amount == 0) ? count : -1; // -1 if not possible
}

int main() {
    vector<int> coins = {1, 2, 5, 10};
    int amount = 23;
    cout << "Minimum coins: " << minCoins(coins, amount) << endl;
    return 0;
}
