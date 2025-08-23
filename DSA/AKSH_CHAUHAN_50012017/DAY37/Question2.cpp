#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> s;

    for (char ch : exp) {
        if (isdigit(ch)) {
            s.push(ch - '0');  // convert char to int
        } else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();
}

int main() {
    string expression = "231*+9-";
    cout << "Postfix Evaluation Result: " << evaluatePostfix(expression) << endl;
    return 0;
}
