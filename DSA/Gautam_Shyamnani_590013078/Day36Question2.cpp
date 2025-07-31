#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string str) {
    stack<char> s;

    for (char ch : str) {
        
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        
        else if (ch == ')' || ch == '}' || ch == ']') {
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

    return s.empty(); 
}

int main() {
    string input = "([])";
    cout << "Input: " << input << endl;
    cout << "Output: " << (isBalanced(input) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}
