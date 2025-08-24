#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxActivities(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<pair<int,int>> activities(n);
    for(int i = 0; i < n; i++) {
        activities[i] = {end[i], start[i]};
    }
    sort(activities.begin(), activities.end()); // sort by finish time

    int count = 0;
    int lastEnd = -1;
    for(auto &act : activities) {
        if(act.second >= lastEnd) {
            count++;
            lastEnd = act.first;
        }
    }
    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};
    cout << "Maximum number of activities: " << maxActivities(start, end) << endl;

    return 0;
}
