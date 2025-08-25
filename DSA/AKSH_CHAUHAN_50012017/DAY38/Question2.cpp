#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> mainStack;
    stack<int> minStack;

public:
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);
    }

    void pop() {
        if (mainStack.top() == minStack.top())
            minStack.pop();
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack s;
    s.push(8);
    s.push(2);
    s.push(6);
    s.pop();

    cout << "Minimum element: " << s.getMin() << endl;
    return 0;
}
