#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string largestNumber(vector<int>& nums) {
    // Convert numbers to strings
    vector<string> strs;
    for (int num : nums) {
        strs.push_back(to_string(num));
    }
    sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });
    if (strs[0] == "0") {
        return "0";
    }
    string result = "";
    for (const string& str : strs) {
        result += str;
    }
    return result;
}
bool customCompare(const string& a, const string& b) {
    return a + b > b + a;
}
string largestNumberAlternative(vector<int>& nums) {
    vector<string> strs;
    for (int num : nums) {
        strs.push_back(to_string(num));
    }
    sort(strs.begin(), strs.end(), customCompare);
    if (strs[0] == "0") {
        return "0";
    }
    string result = "";
    for (const string& str : strs) {
        result += str;
    }
    return result;
}
string largestNumberRobust(vector<int>& nums) {
    if (nums.empty()) return "0";
    vector<string> strs;
    for (int num : nums) {
        strs.push_back(to_string(num));
    }
    sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });
    bool allZeros = true;
    for (const string& str : strs) {
        if (str != "0") {
            allZeros = false;
            break;
        }
    }
    if (allZeros) return "0";
    string result = "";
    for (const string& str : strs) {
        result += str;
    }
    return result;
}
