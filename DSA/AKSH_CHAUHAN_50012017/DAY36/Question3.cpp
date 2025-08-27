#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(top);
}
int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    insertAtBottom(s, 0);

    // Print stack from top to bottom
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    // Output: 3 2 1 0 (top to bottom, so visually it's [0,1,2,3])
    return 0;
}
