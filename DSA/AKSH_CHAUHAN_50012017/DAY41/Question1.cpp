#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeDuplicates(string s) {
    stack<char> st;

    for (char ch : s) {
        if (!st.empty() && st.top() == ch) {
            st.pop(); // Remove the duplicate
        } else {
            st.push(ch);
        }
    }

    // Rebuild the string from stack
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;
}

int main() {
    string s = "abbaca";
    cout << "Reduced String: " << removeDuplicates(s) << endl;
    return 0;
}
