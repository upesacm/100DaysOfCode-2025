#include <iostream>
#include <string>
using namespace std;

string removeKdigits(string num, int k) {
    string result;

    for (char digit : num) {
        while (!result.empty() && k > 0 && result.back() > digit) {
            result.pop_back();  // Remove larger digit for smaller lexicographic value
            k--;
        }
        result.push_back(digit);
    }

    // If there are still digits to remove, remove from the end
    while (k > 0 && !result.empty()) {
        result.pop_back();
        k--;
    }

    // Remove leading zeros
    int start = 0;
    while (start < result.size() && result[start] == '0') {
        start++;
    }

    string trimmed = result.substr(start);
    return trimmed.empty() ? "0" : trimmed;
}

int main() {
    cout << removeKdigits("1432219", 3) << endl; // Output: 1219
    cout << removeKdigits("10200", 1) << endl;   // Output: 200
    return 0;
}
