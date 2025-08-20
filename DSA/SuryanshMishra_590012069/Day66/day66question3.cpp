#include <vector>
#include <algorithm>
using namespace std;
int minCandies(vector<int>& ratings) {
    int n = ratings.size();
    if (n == 0) return 0;    
    vector<int> candies(n, 1);
    // Left to right pass: ensure higher rated child gets more than left neighbor
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    
    // Right to left pass: ensure higher rated child gets more than right neighbor
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }
    
    // Calculate total candies
    int total = 0;
    for (int candy : candies) {
        total += candy;
    }
    
    return total;
}

// Alternative version that returns both total and distribution
pair<int, vector<int>> minCandiesWithDistribution(vector<int>& ratings) {
    int n = ratings.size();
    if (n == 0) return {0, {}};
    
    vector<int> candies(n, 1); // Each child gets at least 1 candy
    
    // Left to right pass: ensure higher rated child gets more than left neighbor
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    
    // Right to left pass: ensure higher rated child gets more than right neighbor
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }
    
    // Calculate total candies
    int total = 0;
    for (int candy : candies) {
        total += candy;
    }
    
    return {total, candies};
}

// Space-optimized version using constant extra space
int minCandiesOptimized(vector<int>& ratings) {
    int n = ratings.size();
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int total = 1; // First child gets 1 candy
    int up = 0, down = 0, peak = 0;
    
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            up++;
            down = 0;
            peak = up;
            total += 1 + up;
        } else if (ratings[i] == ratings[i - 1]) {
            up = down = peak = 0;
            total += 1;
        } else {
            up = 0;
            down++;
            total += 1 + down;
            if (peak < down) {
                total++; // Adjust peak if needed
            }
        }
    }
    
    return total;
}
