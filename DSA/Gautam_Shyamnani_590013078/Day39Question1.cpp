#include <iostream>
#include <stack>
using namespace std;


void insertAtBottom(stack<int>& s, int element) {
    if (s.empty()) {
        s.push(element);  
        return;
    }

    int temp = s.top();
    s.pop();

    insertAtBottom(s, element);  

    s.push(temp);  
}

void reverseStack(stack<int>& s) {
    if (s.empty()) return;

    int temp = s.top();
    s.pop();

    reverseStack(s);          
    insertAtBottom(s, temp);  
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

    cout << "Original stack: ";
    printStack(s);

    reverseStack(s);

    cout << "Reversed stack: ";
    printStack(s);

    return 0;
}
