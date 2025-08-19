#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<pair<int,int>>& intervals) {
    if(intervals.empty()) return 0;
    
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
        return a.second < b.second; // earliest finishing first
    });

    int count = 1;
    int lastEnd = intervals[0].second;
    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[i].first >= lastEnd) {
            count++;
            lastEnd = intervals[i].second;
        }
    }
    return intervals.size() - count; // tasks to remove
}

int main() {
    vector<pair<int,int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << "Minimum tasks to remove: " << eraseOverlapIntervals(intervals) << endl;
    return 0;
}
