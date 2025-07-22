#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int> &input) {
    stack<int> temp;

    while (!input.empty()) {
        int top = input.top();
        input.pop();

        // Move elements from temp back to input if they are greater
        while (!temp.empty() && temp.top() > top) {
            input.push(temp.top());
            temp.pop();
        }

        temp.push(top);
    }

    // Move sorted elements back to original stack
    while (!temp.empty()) {
        input.push(temp.top());
        temp.pop();
    }
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);

    sortStack(s);
    cout << "Sorted Stack (Top to Bottom): ";
    printStack(s);

    return 0;
}
