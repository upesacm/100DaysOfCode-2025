#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minJumps(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1; // cannot move

    int jumps = 1;
    int maxReach = arr[0];
    int steps = arr[0];

    for (int i = 1; i < n; i++) {
        if (i == n - 1) return jumps;

        maxReach = max(maxReach, i + arr[i]);
        steps--;

        if (steps == 0) {
            jumps++;
            if (i >= maxReach) return -1;
            steps = maxReach - i;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {2, 3, 1, 1, 4};
    cout << "Minimum jumps: " << minJumps(arr) << endl;
    return 0;
}
