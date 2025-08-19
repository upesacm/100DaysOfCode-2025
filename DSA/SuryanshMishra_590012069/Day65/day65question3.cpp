#include <vector>
#include <algorithm>
using namespace std;
int minRemovalForNonOverlapping(vector<pair<int, int>>& intervals) {
    int n = intervals.size();
    if (n <= 1) return 0;    
    sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });    
    int kept = 1;
    int lastEnd = intervals[0].second;    
    for (int i = 1; i < n; i++) {
        int currentStart = intervals[i].first;        
        if (currentStart >= lastEnd) {
            kept++;
            lastEnd = intervals[i].second;
        }
    }
    return n - kept;
}
pair<int, vector<pair<int, int>>> minRemovalWithRemaining(vector<pair<int, int>>& intervals) {
    int n = intervals.size();
    if (n <= 1) return {0, intervals};    
    sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    vector<pair<int, int>> remaining;
    remaining.push_back(intervals[0]);
    int lastEnd = intervals[0].second;    
    for (int i = 1; i < n; i++) {
        int currentStart = intervals[i].first;        
        if (currentStart >= lastEnd) {
            remaining.push_back(intervals[i]);
            lastEnd = intervals[i].second;
        }
    }    
    int removed = n - remaining.size();
    return {removed, remaining};
}
