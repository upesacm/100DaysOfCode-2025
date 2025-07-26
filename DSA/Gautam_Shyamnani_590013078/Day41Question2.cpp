#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(const string& s) {
    stack<int> countStack;
    stack<string> strStack;
    string currentStr = "";
    int k = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            k = k * 10 + (ch - '0');  // Build multi-digit count
        } else if (ch == '[') {
            countStack.push(k);
            strStack.push(currentStr);
            k = 0;
            currentStr = "";
        } else if (ch == ']') {
            int count = countStack.top(); countStack.pop();
            string decoded = "";
            for (int i = 0; i < count; ++i) {
                decoded += currentStr;
            }
            currentStr = strStack.top() + decoded;
            strStack.pop();
        } else {
            currentStr += ch;  // Regular character
        }
    }

    return currentStr;
}

int main() {
    cout << decodeString("3[a]2[bc]") << endl;        // Output: aaabcbc
    cout << decodeString("2[abc]3[cd]ef") << endl;    // Output: abcabccdcdcdef
    return 0;
}
