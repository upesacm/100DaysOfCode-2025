#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int> &s, int current, int middle) {
    if (current == middle) {
        s.pop(); // Remove middle element
        return;
    }

    int top = s.top();
    s.pop();

    deleteMiddle(s, current + 1, middle);

    s.push(top); // Put the element back
}

void deleteMiddleElement(stack<int> &s) {
    int size = s.size();
    int middle = size / 2; // 0-based indexing
    deleteMiddle(s, 0, middle);
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
    s.push(4);
    s.push(5);

    deleteMiddleElement(s);

    cout << "Stack after deleting middle element: ";
    printStack(s);

    return 0;
}
