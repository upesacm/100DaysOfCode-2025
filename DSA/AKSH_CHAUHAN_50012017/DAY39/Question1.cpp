#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }
    int top = s.top(); s.pop();
    insertAtBottom(s, x);
    s.push(top);
}

void reverseStack(stack<int> &s) {
    if (s.empty()) return;
    int top = s.top(); s.pop();
    reverseStack(s);
    insertAtBottom(s, top);
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
    s.push(1);
    s.push(2);
    s.push(3);

    reverseStack(s);

    cout << "Reversed Stack: ";
    printStack(s);

    return 0;
}
