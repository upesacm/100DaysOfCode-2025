#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
double fractionalKnapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    if (n == 0 || capacity <= 0) return 0.0;
    vector<pair<double, int>> items;
    for (int i = 0; i < n; i++) {
        double ratio = (double)values[i] / weights[i];
        items.push_back({ratio, i});
    }    
    sort(items.begin(), items.end(), greater<pair<double, int>>());    
    double totalValue = 0.0;
    int remainingCapacity = capacity;
    for (auto& item : items) {
        int idx = item.second;
        int weight = weights[idx];
        int value = values[idx];
        if (weight <= remainingCapacity) {
            totalValue += value;
            remainingCapacity -= weight;
        } else {
            double fraction = (double)remainingCapacity / weight;
            totalValue += fraction * value;
            break;
        }
    }
    return totalValue;
}
