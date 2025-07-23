#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);  
    stack<int> s;  

    for (int i = 0; i < n; ++i) {
        
        while (!s.empty() && nums[i] > nums[s.top()]) {
            result[s.top()] = nums[i];  
            s.pop();  
        }
        s.push(i);  
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> ans = nextGreaterElements(arr);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
