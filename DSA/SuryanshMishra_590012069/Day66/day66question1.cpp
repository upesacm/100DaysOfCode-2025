#include <vector>
#include <algorithm>
using namespace std;
int minPlatforms(vector<int>& arrivals, vector<int>& departures) {
    int n = arrivals.size();
    if (n == 0) return 0;    
    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());    
    int platforms = 0;
    int maxPlatforms = 0;
    int i = 0, j = 0;    
    while (i < n && j < n) {
        if (arrivals[i] <= departures[j]) {
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        }
        else {
            platforms--;
            j++;
        }
    }    
    return maxPlatforms;
}
int minPlatformsEvents(vector<int>& arrivals, vector<int>& departures) {
    int n = arrivals.size();
    if (n == 0) return 0;    
    vector<pair<int, int>> events;    
    for (int i = 0; i < n; i++) {
        events.push_back({arrivals[i], 1});
        events.push_back({departures[i], -1});
    }
    sort(events.begin(), events.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });    
    int platforms = 0;
    int maxPlatforms = 0;    
    for (const auto& event : events) {
        platforms += event.second;
        maxPlatforms = max(maxPlatforms, platforms);
    }    
    return maxPlatforms;
}
