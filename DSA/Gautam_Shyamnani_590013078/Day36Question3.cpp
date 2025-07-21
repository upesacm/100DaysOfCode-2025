#include <iostream>
#include <stack>
using namespace std;


void insertAtBottom(stack<int>& s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }

    int topElement = s.top();
    s.pop();

    
    insertAtBottom(s, x);

    s.push(topElement);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    int x = 0;
    insertAtBottom(s, x);

    
    cout << "Stack after inserting at bottom:\n";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
