#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Return largest number formed by arranging array elements
string largestNumber(vector<int>& nums) {
    // Convert numbers to strings
    vector<string> strs;
    for (int num : nums) {
        strs.push_back(to_string(num));
    }
    
    // Custom comparator: compare a+b vs b+a
    sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });
    
    // Handle edge case: all zeros
    if (strs[0] == "0") {
        return "0";
    }
    
    // Concatenate sorted strings
    string result = "";
    for (const string& str : strs) {
        result += str;
    }
    
    return result;
}

// Alternative version with explicit comparator function
bool customCompare(const string& a, const string& b) {
    return a + b > b + a;
}

string largestNumberAlternative(vector<int>& nums) {
    // Convert numbers to strings
    vector<string> strs;
    for (int num : nums) {
        strs.push_back(to_string(num));
    }
    
    // Sort using custom comparator
    sort(strs.begin(), strs.end(), customCompare);
    
    // Handle edge case: all zeros
    if (strs[0] == "0") {
        return "0";
    }
    
    // Concatenate sorted strings
    string result = "";
    for (const string& str : strs) {
        result += str;
    }
    
    return result;
}

// Version that handles edge cases more explicitly
string largestNumberRobust(vector<int>& nums) {
    if (nums.empty()) return "0";
    
    // Convert numbers to strings
    vector<string> strs;
    for (int num : nums) {
        strs.push_back(to_string(num));
    }
    
    // Custom comparator: for optimal arrangement, a should come before b
    // if concatenating a+b gives larger number than b+a
    sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });
    
    // Check if result would be all zeros
    bool allZeros = true;
    for (const string& str : strs) {
        if (str != "0") {
            allZeros = false;
            break;
        }
    }
    
    if (allZeros) return "0";
    
    // Concatenate sorted strings
    string result = "";
    for (const string& str : strs) {
        result += str;
    }
    
    return result;
}
