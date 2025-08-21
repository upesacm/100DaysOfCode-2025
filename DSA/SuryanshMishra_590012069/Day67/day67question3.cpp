#include <vector>
#include <algorithm>
using namespace std;

// Return maximum number of non-overlapping meetings
int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    if (n == 0) return 0;
    
    // Create meeting intervals with their indices
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++) {
        meetings.push_back({end[i], start[i]}); // Store as (end_time, start_time)
    }
    
    // Sort by end time (earliest finish first)
    sort(meetings.begin(), meetings.end());
    
    int count = 1; // First meeting is always selected
    int lastEndTime = meetings[0].first;
    
    // Greedily select non-overlapping meetings
    for (int i = 1; i < n; i++) {
        int currentStart = meetings[i].second;
        int currentEnd = meetings[i].first;
        
        // If current meeting starts after last meeting ends, select it
        if (currentStart >= lastEndTime) {
            count++;
            lastEndTime = currentEnd;
        }
    }
    
    return count;
}

// Alternative version that returns the actual meeting indices
pair<int, vector<int>> maxMeetingsWithIndices(vector<int>& start, vector<int>& end) {
    int n = start.size();
    if (n == 0) return {0, {}};
    
    // Create meeting intervals with their original indices
    vector<pair<pair<int, int>, int>> meetings;
    for (int i = 0; i < n; i++) {
        meetings.push_back({{end[i], start[i]}, i}); // {(end_time, start_time), original_index}
    }
    
    // Sort by end time (earliest finish first)
    sort(meetings.begin(), meetings.end());
    
    vector<int> selectedMeetings;
    selectedMeetings.push_back(meetings[0].second); // Add first meeting index
    int lastEndTime = meetings[0].first.first;
    
    // Greedily select non-overlapping meetings
    for (int i = 1; i < n; i++) {
        int currentStart = meetings[i].first.second;
        int currentEnd = meetings[i].first.first;
        int originalIndex = meetings[i].second;
        
        // If current meeting starts after last meeting ends, select it
        if (currentStart >= lastEndTime) {
            selectedMeetings.push_back(originalIndex);
            lastEndTime = currentEnd;
        }
    }
    
    return {selectedMeetings.size(), selectedMeetings};
}

// Version that works with meeting structures
struct Meeting {
    int start;
    int end;
    int id;
};

int maxMeetingsStruct(vector<Meeting>& meetings) {
    if (meetings.empty()) return 0;
    
    // Sort by end time (earliest finish first)
    sort(meetings.begin(), meetings.end(), [](const Meeting& a, const Meeting& b) {
        return a.end < b.end;
    });
    
    int count = 1; // First meeting is always selected
    int lastEndTime = meetings[0].end;
    
    // Greedily select non-overlapping meetings
    for (int i = 1; i < meetings.size(); i++) {
        // If current meeting starts after last meeting ends, select it
        if (meetings[i].start >= lastEndTime) {
            count++;
            lastEndTime = meetings[i].end;
        }
    }
    
    return count;
}
