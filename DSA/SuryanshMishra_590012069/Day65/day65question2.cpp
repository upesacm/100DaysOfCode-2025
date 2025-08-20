#include <vector>
#include <algorithm>
using namespace std;
int maxChainLength(vector<pair<int, int>>& pairs) {
    int n = pairs.size();
    if (n == 0) return 0;
    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }); 
    int chainLength = 1;
    int lastEnd = pairs[0].second;    
    for (int i = 1; i < n; i++) {
        int currentStart = pairs[i].first;        
        if (currentStart > lastEnd) {
            chainLength++;
            lastEnd = pairs[i].second;
        }
    }    
    return chainLength;
}
vector<pair<int, int>> maxChainPairs(vector<pair<int, int>>& pairs) {
    int n = pairs.size();
    if (n == 0) return {};    
    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });    
    vector<pair<int, int>> chain;
    chain.push_back(pairs[0]);
    int lastEnd = pairs[0].second;    
    for (int i = 1; i < n; i++) {
        int currentStart = pairs[i].first;        
        if (currentStart > lastEnd) {
            chain.push_back(pairs[i]);
            lastEnd = pairs[i].second;
        }
    }
    return chain;
}