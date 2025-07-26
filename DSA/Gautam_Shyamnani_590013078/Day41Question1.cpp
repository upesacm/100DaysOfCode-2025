#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeAdjacentDuplicates(string s) {
    while (true) {
        stack<char> st;
        bool removed = false;

        for (int i = 0; i < s.length(); ++i) {
            if (!st.empty() && st.top() == s[i]) {
                st.pop();   // Remove the duplicate
                removed = true;
            } else {
                st.push(s[i]);
            }
        }

        // Reconstruct the string from stack
        string reduced;
        while (!st.empty()) {
            reduced = st.top() + reduced;
            st.pop();
        }

        if (!removed) break;
        s = reduced;
    }

    return s;
}

int main() {
    cout << removeAdjacentDuplicates("abbaca") << endl; // Output: ca
    cout << removeAdjacentDuplicates("azxxzy") << endl; // Output: ay

    return 0;
}
