#include <vector>
#include <algorithm>
using namespace std;
int maxActivities(vector<int>& start, vector<int>& end) {
    int n = start.size();
    if (n == 0) return 0;
    vector<pair<int, int>> activities;
    for (int i = 0; i < n; i++) {
        activities.push_back({end[i], start[i]});
    }
    sort(activities.begin(), activities.end());
    
    int count = 1;
    int lastEndTime = activities[0].first;
    for (int i = 1; i < n; i++) {
        int currentStart = activities[i].second;
        if (currentStart >= lastEndTime) {
            count++;
            lastEndTime = activities[i].first;
        }
    }
    return count;
}