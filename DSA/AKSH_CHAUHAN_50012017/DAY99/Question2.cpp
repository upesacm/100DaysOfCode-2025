#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct MaxStack {
    stack<pair<int,int>> st;
    void push(int x) {
        int mx = st.empty() ? x : max(x, st.top().second);
        st.push({x,mx});
    }
    int pop() {
        int x = st.top().first;
        st.pop();
        return x;
    }
    int getMax() {
        return st.top().second;
    }
    bool empty() { return st.empty(); }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MaxStack s1, s2;
    auto move = [&]() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int val = s1.pop();
                int mx = s2.empty() ? val : max(val, s2.getMax());
                s2.st.push({val, mx});
            }
        }
    };

    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        s1.push(nums[i]);
        if (i >= k-1) {
            move();
            res.push_back(max(s1.empty() ? INT_MIN : s1.getMax(),
                              s2.empty() ? INT_MIN : s2.getMax()));
            s2.pop();
        }
    }
    return res;
}

int main() {
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = maxSlidingWindow(arr, k);
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
