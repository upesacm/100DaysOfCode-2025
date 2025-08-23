#include <iostream>
#include <stack>
using namespace std;

bool hasRedundantBrackets(string expr) {
    stack<char> s;

    for (char ch : expr) {
        if (ch == ')') {
            bool isRedundant = true;
            while (!s.empty() && s.top() != '(') {
                char top = s.top();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    isRedundant = false;
                s.pop();
            }
            s.pop(); // Remove the opening '('
            if (isRedundant) return true;
        } else {
            s.push(ch);
        }
    }
    return false;
}

int main() {
    string expr = "((a+b))";
    if (hasRedundantBrackets(expr))
        cout << "Yes (Redundant brackets found)" << endl;
    else
        cout << "No (No redundant brackets)" << endl;

    return 0;
}
