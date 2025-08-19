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
        // Otherwise, we remove this interval (don't increment kept)
    }
    
    return n - kept; // Total intervals - kept intervals = removed intervals
}

// Alternative version that returns both removed count and remaining intervals
pair<int, vector<pair<int, int>>> minRemovalWithRemaining(vector<pair<int, int>>& intervals) {
    int n = intervals.size();
    if (n <= 1) return {0, intervals};
    
    // Sort intervals by end time (greedy: keep intervals that end earliest)
    sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    
    vector<pair<int, int>> remaining;
    remaining.push_back(intervals[0]); // First interval is always kept
    int lastEnd = intervals[0].second;
    
    // Greedily keep non-overlapping intervals
    for (int i = 1; i < n; i++) {
        int currentStart = intervals[i].first;
        
        // If current interval doesn't overlap with last kept interval
        if (currentStart >= lastEnd) {
            remaining.push_back(intervals[i]);
            lastEnd = intervals[i].second;
        }
        // Otherwise, we remove this interval
    }
    
    int removed = n - remaining.size();
    return {removed, remaining};
}
