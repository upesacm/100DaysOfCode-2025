#include <iostream>
#include <stack>
using namespace std;


int applyOperator(char op, int a, int b) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; 
    }
    return 0;
}


int evaluatePostfix(const string& expr) {
    stack<int> s;

    for (char token : expr) {
        if (isdigit(token)) {
           
            s.push(token - '0');
        } else {
           
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            int result = applyOperator(token, a, b);
            s.push(result);
        }
    }

    
    return s.top();
}

int main() {
    string expression1 = "231*+9-";
    cout << "Evaluating: " << expression1 << endl;
    cout << "Result: " << evaluatePostfix(expression1) << endl;

    string expression2 = "52+";
    cout << "\nEvaluating: " << expression2 << endl;
    cout << "Result: " << evaluatePostfix(expression2) << endl;

    return 0;
}
