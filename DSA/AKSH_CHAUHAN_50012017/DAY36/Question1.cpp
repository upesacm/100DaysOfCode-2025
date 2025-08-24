#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str) {
    stack<char> s;

    // Push each character onto the stack
    for (char ch : str) {
        s.push(ch);
    }

    // Pop characters to build reversed string
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}
int main() {
    cout << reverseString("hello") << endl;  // Output: olleh
    cout << reverseString("abcde") << endl;  // Output: edcba
    return 0;
}
