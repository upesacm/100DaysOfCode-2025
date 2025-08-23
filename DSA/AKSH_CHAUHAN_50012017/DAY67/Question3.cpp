#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<pair<int,int>> meetings;
    for (int i = 0; i < n; i++) {
        meetings.push_back({end[i], start[i]});
    }

    sort(meetings.begin(), meetings.end()); // sort by finish time

    int count = 0;
    int lastEnd = -1;
    for (auto &m : meetings) {
        if (m.second >= lastEnd) {
            count++;
            lastEnd = m.first;
        }
    }
    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};
    cout << "Maximum non-overlapping meetings: " << maxMeetings(start, end) << endl;
    return 0;
}
