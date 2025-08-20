#include <vector>
#include <algorithm>
using namespace std;
int minPlatforms(vector<int>& arrivals, vector<int>& departures) {
    int n = arrivals.size();
    if (n == 0) return 0;
    
    // Sort arrival and departure times
    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());
    
    int platforms = 0;
    int maxPlatforms = 0;
    int i = 0, j = 0;
    
    // Use two pointers to process events chronologically
    while (i < n && j < n) {
        // If next event is arrival, increment platform count
        if (arrivals[i] <= departures[j]) {
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        }
        // If next event is departure, decrement platform count
        else {
            platforms--;
            j++;
        }
    }
    
    return maxPlatforms;
}

// Alternative approach using event-based processing
int minPlatformsEvents(vector<int>& arrivals, vector<int>& departures) {
    int n = arrivals.size();
    if (n == 0) return 0;
    
    // Create events: (time, type) where type = 1 for arrival, -1 for departure
    vector<pair<int, int>> events;
    
    for (int i = 0; i < n; i++) {
        events.push_back({arrivals[i], 1});    // Arrival event
        events.push_back({departures[i], -1}); // Departure event
    }
    
    // Sort events by time, with departures before arrivals at same time
    sort(events.begin(), events.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second; // Departure (-1) before arrival (1)
        }
        return a.first < b.first;
    });
    
    int platforms = 0;
    int maxPlatforms = 0;
    
    // Process events chronologically
    for (const auto& event : events) {
        platforms += event.second; // +1 for arrival, -1 for departure
        maxPlatforms = max(maxPlatforms, platforms);
    }
    
    return maxPlatforms;
}
