#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeKdigits(string num, int k) {
    stack<char> st;

    for (char digit : num) {
        while (!st.empty() && k > 0 && st.top() > digit) {
            st.pop();
            k--;
        }
        st.push(digit);
    }

    // If k > 0, remove more digits from the end
    while (k-- > 0 && !st.empty()) {
        st.pop();
    }

    // Build result string
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    // Remove leading zeros
    int index = 0;
    while (index < result.length() && result[index] == '0') index++;

    result = result.substr(index);
    return result.empty() ? "0" : result;
}

int main() {
    string num = "1432219";
    int k = 3;
    cout << "Smallest number: " << removeKdigits(num, k) << endl;
    return 0;
}
