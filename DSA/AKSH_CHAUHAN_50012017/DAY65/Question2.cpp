#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxChainLength(vector<pair<int,int>>& pairs) {
    sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
        return a.second < b.second; // sort by end
    });
    
    int count = 0;
    int lastEnd = INT_MIN;
    for(auto &p : pairs) {
        if(p.first > lastEnd) {
            count++;
            lastEnd = p.second;
        }
    }
    return count;
}

int main() {
    vector<pair<int,int>> pairs = {{5,24},{15,25},{27,40},{50,60}};
    cout << "Maximum chain length: " << maxChainLength(pairs) << endl;
    return 0;
}
