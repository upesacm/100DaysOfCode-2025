#include <iostream>
#include <stack>
using namespace std;

class MaxStack {
    stack<int> mainStack;
    stack<int> maxStack;

public:
    void push(int x) {
        mainStack.push(x);
        if (maxStack.empty() || x >= maxStack.top())
            maxStack.push(x);
    }

    void pop() {
        if (mainStack.top() == maxStack.top())
            maxStack.pop();
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMax() {
        return maxStack.top();
    }
};

int main() {
    MaxStack s;
    s.push(3);
    s.push(5);
    s.push(2);

    cout << "Max element: " << s.getMax() << endl; // Should print 5
    s.pop(); // Pops 2
    cout << "Max element: " << s.getMax() << endl; // Should print 5
    s.pop(); // Pops 5
    cout << "Max element: " << s.getMax() << endl; // Should print 3

    return 0;
}
