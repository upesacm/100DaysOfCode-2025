#include <vector>
#include <algorithm>
using namespace std;
int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    if (n == 0) return 0;
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++) {
        meetings.push_back({end[i], start[i]});
    }
    sort(meetings.begin(), meetings.end());
    int count = 1;
    int lastEndTime = meetings[0].first;
    for (int i = 1; i < n; i++) {
        int currentStart = meetings[i].second;
        int currentEnd = meetings[i].first;
        if (currentStart >= lastEndTime) {
            count++;
            lastEndTime = currentEnd;
        }
    }
    return count;
}
pair<int, vector<int>> maxMeetingsWithIndices(vector<int>& start, vector<int>& end) {
    int n = start.size();
    if (n == 0) return {0, {}};
    vector<pair<pair<int, int>, int>> meetings;
    for (int i = 0; i < n; i++) {
        meetings.push_back({{end[i], start[i]}, i});
    }
    sort(meetings.begin(), meetings.end());
    vector<int> selectedMeetings;
    selectedMeetings.push_back(meetings[0].second);
    int lastEndTime = meetings[0].first.first;
    for (int i = 1; i < n; i++) {
        int currentStart = meetings[i].first.second;
        int currentEnd = meetings[i].first.first;
        int originalIndex = meetings[i].second;
        if (currentStart >= lastEndTime) {
            selectedMeetings.push_back(originalIndex);
            lastEndTime = currentEnd;
        }
    }
    return {selectedMeetings.size(), selectedMeetings};
}
struct Meeting {
    int start;
    int end;
    int id;
};
int maxMeetingsStruct(vector<Meeting>& meetings) {
    if (meetings.empty()) return 0;
    sort(meetings.begin(), meetings.end(), [](const Meeting& a, const Meeting& b) {
        return a.end < b.end;
    });
    int count = 1;
    int lastEndTime = meetings[0].end;
    for (int i = 1; i < meetings.size(); i++) {
        if (meetings[i].start >= lastEndTime) {
            count++;
            lastEndTime = meetings[i].end;
        }
    }
    return count;
}
