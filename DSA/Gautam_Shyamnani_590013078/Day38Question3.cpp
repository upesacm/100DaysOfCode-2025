#include <iostream>
#include <stack>
using namespace std;

bool hasRedundantBrackets(string expr) {
    stack<char> st;

    for (char ch : expr) {
        if (ch == ')') {
            bool hasOperator = false;

            
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                st.pop();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    hasOperator = true;
                }
            }

            
            if (!st.empty()) {
                st.pop();
            }

            if (!hasOperator) return true;
        } else {
            st.push(ch);  
        }
    }

    return false;
}

int main() {
    string expr1 = "((a+b))";
    string expr2 = "(a+b)";

    cout << (hasRedundantBrackets(expr1) ? "Yes" : "No") << endl;  // Yes
    cout << (hasRedundantBrackets(expr2) ? "Yes" : "No") << endl;  // No

    return 0;
}
