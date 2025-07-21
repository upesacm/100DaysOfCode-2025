#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string str) {
    stack<char> s;
    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;

            char top = s.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty(); // If stack is empty at end, it's balanced
}
int main() {
    cout << (isBalanced("([])") ? "Balanced" : "Not Balanced") << endl; // Balanced
    cout << (isBalanced("([") ? "Balanced" : "Not Balanced") << endl;   // Not Balanced
    return 0;
}
