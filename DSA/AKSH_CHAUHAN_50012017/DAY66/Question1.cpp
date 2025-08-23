#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platforms = 0, maxPlatforms = 0;
    int i = 0, j = 0;

    while(i < n && j < n) {
        if(arr[i] <= dep[j]) { // train arrives
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        } else { // train departs
            platforms--;
            j++;
        }
    }
    return maxPlatforms;
}

int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << "Minimum platforms required: " << findPlatform(arr, dep) << endl;
    return 0;
}
