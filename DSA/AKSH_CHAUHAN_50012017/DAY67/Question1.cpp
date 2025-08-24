#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string largestNumber(vector<int>& nums) {
    vector<string> arr;
    for (int n : nums) arr.push_back(to_string(n));

    sort(arr.begin(), arr.end(), [](string &a, string &b) {
        return a + b > b + a; // custom comparator
    });

    if (arr[0] == "0") return "0"; // handle all zeros
    string result = "";
    for (string &s : arr) result += s;
    return result;
}

int main() {
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << "Largest Number: " << largestNumber(nums) << endl;
    return 0;
}
