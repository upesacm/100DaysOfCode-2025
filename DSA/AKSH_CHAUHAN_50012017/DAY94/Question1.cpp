#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> lis;
    for (int x : nums) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) lis.push_back(x);
        else *it = x;
    }
    return lis.size();
}

int main() {
    vector<int> arr = {10,9,2,5,3,7,101,18};
    cout << "Length of LIS: " << lengthOfLIS(arr) << endl;
    return 0;
}
